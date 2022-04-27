.data
	infix: .space 256
	postfix: .space 256
	prefix: .space 256
    output: .space 256
	beginMsg: .asciiz "Enter infix expression:\nRemember to use closed paren and a num between 0-9\n\nInput:  "
	infixExpression: .asciiz "Infix expression: "
	postfixExpression: .asciiz "Postfix expression: "
    postfixlen: .asciiz "Postfix length: "
	s1: .asciiz "S1: "
	resultIs: .asciiz "result is: "
	numb: .asciiz "Found a Number: "
	plus: .asciiz "Found a plus: "
	minus: .asciiz "Found a minus: "
	s0: .asciiz "S0: "
	firstNumber: .asciiz "first num is: "
	secondNumber: .asciiz "second num is: "
	result:  .asciiz "\nEvaluation: "
	currentpointernum: .asciiz "Current index: "
    preorder: .asciiz "Preorder: "
	 p: .word 0 # my pointer to dynamic memory.
	 x: .word 0
	 stack2: .space 256
	 stack3: .space 256
     spacer: .asciiz "==========================================="
	.text 
.globl main 
	
main:
# Get the infix expression
	# print beginning
	li $v0, 4
	la $a0, beginMsg 
	syscall
	
	li $v0, 8     # get input
	la $a0, infix # $a0 = buffer
 	la $a1, 256   # $a1 = maximum number of characters to read
 	syscall
	
##############################################	

# Print infix 
	# print string
	li $v0, 4
	la $a0, infixExpression # $a0 = address of null-terminated string to print
	syscall
	
	# print string
	li $v0, 4
	la $a0, infix # print infix
	syscall
	
	#print character for a newline
	li $v0, 11
	li $a0, '\n'
	syscall

##############################################	
	
	la $t1, infix		# $t1 = infix
	li $s0,0            # $s0 = length
	findlength:
	lb $t2,($t1)        # $t2 = character
	addi $t1,$t1,1      # increment $t1
	addi $s0,$s0,1      # increment $s0
	bne $t2, 0, findlength # 
	
	#addi $s0, -2 # because offset by 2 more actual is 2 less I COMMENTED OUT THIS
##############################################		
	
	li $t5,-1		# Postfix top offset
	la $t2, postfix # $t2 = postfix
	la $t1, infix   # $t1 = infix
	addi $t1,$t1,-1	# Set initial address of infix to -1 because we add one at start of scan
	li,$s1,0        # s1 = counter 
	#addi $s0, $s0, -1 #WE HAVE ALTERED THIS AS WELL
	addi $sp,$sp,1
	
	scanInfix:
	addi $s1,$s1,1	# increment counter
	addi $t1,$t1,1  # increment infix
	lb $t4,($t1) # get next character
	# checks
	beq $t4,'0',number
	beq $t4,'1',number
	beq $t4,'2',number
	beq $t4,'3',number
	beq $t4,'4',number
	beq $t4,'5',number
	beq $t4,'6',number
	beq $t4,'7',number
	beq $t4,'8',number
	beq $t4,'9',number
	beq $t4, '+', addsub
	beq $t4, '-', addsub
	beq $t4, '(', openp
	beq $t4, ')', closep
	
	go:
	bne $s1,$s0,scanInfix # if not end of infix, go to scanInfix
	
# Print postfixfix 
	# print string
	li $v0, 4
	la $a0, postfixExpression # $a0 = address of null-terminated string to print
	syscall
	

    # TODO: take postfix and evaluate HERE

    # then print postfix = x
    # MOVED TO EXIT
	
	
##############################################
	# finding length of postfix
	li $s0,0 # $s0 = length
	la $t2, postfix # $t2 = postfix
	postfixlength:
	lb $t1,($t2)    # $t1 = next character
	addi $t2,$t2,1 # increment postfix stack
	addi $s0,$s0,1 # increment length
	bne $t1, 0, postfixlength # if not end of postfix, go to postfixlength
	
	#addi $s0, -1 # because offset by 1 more actual is 1 less  I COMMENTED OUT THIS
	li,$s1,0 # counter
	# print string
	li $v0, 4
	# print postfix
	la $a0, postfix
	syscall
	# print character for a newline
	li $v0, 11
	li $a0, '\n'
	syscall
	addi $s0,$s0,-1
    # print string
    li $v0, 4
    la $a0, postfixlen
    syscall
    # s0 = length of postfix
	li $v0, 1 
    move $a0, $s0 # PRINT s0
	syscall
    la $s3, output # $s3 = output
	la $s5, stack2
	la $s6, stack3
    li $s2, 0
    la $s2, postfix # $s2 = postfix
    # goto loop2
    addi $s2, $s2, -1 # add 1 at start of loop
	li $s1, 0 # counter
    j loop2






#########################
continue:
    li $v0, 4 # print string
	la $a0, postfix # print postfix
	syscall
    # print result
    li $v0, 4
    la $a0, result
    syscall


	
##############################################
	
	openp:
	sub $sp,$sp,1 # decrement stack pointer
	sb $t4,0($sp) # store open paren
	j go
	
	closep:
	loop:
	lb $t4, 0($sp) # get next character
	beq $t4, '-', append # if minus, go to append to store
	beq $t4, '+', append # if plus, go to append to store
	beq $t4, '(',incloop # if open paren, increment loop
	incloop:
	addi $sp,$sp,1

	j go
	
	addsub:
	sub $sp,$sp,1	# decrement stack pointer
	sb $t4,0($sp) # push operator onto stack
	j go
	
	number:
	addi $t5,$t5,1 # increment value location
	add $t8,$t5,$t2	# t8 = value location 
	sb $t4,($t8) # store value
	j go
	
	append:
	addi $t5,$t5,1 # increment value location
	add $t8,$t5,$t2		# t8 = value location	
	sb $t4,($t8) # store value
	addi $sp,$sp,1 # increment stack pointer
	j loop
	#################################
# 1) Create a stack to store operands (or values). 
# 2) Scan the given expression and do the following for every scanned element. 
    # ..a) If the element is a number, push it into the stack 
    # ..b) If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
# 3) When the expression is ended, the number in the stack is the final answer 






#**************************************TAKING OVER FROM THIS POINT**************************************





loop2:
# When the expression is ended, the number in the stack is the final answer 
# iterate postfix expression, add numbers to stack, operators pull numbers off - operate and store back on, final num in stack is result
	addi $s2,$s2,1 # increment postfix stack ------- Starting at [s2][1][-][]
	addi $s1,$s1,1	# increment counter
	lb $t0, 0($s2) # get next character loop2 
	# print current thing in stack

		# if null terminator, exit loop and go print
		beq $t0, 0, finish
		beq $t0, '0', num
		beq $t0, '1', num
		beq $t0, '2', num
		beq $t0, '3', num
		beq $t0, '4', num
		beq $t0, '5', num
		beq $t0, '6', num
		beq $t0, '7', num
		beq $t0, '8', num
		beq $t0, '9', num
		beq $t0, '+', operatoradd
		beq $t0, '-', operatorsub
		j loop2

	next:
		beq $s1,$s0, finish
		bne $s1,$s0,loop2 # if not end of postfix, go to loop2
		# ..b) If the element is an operator, pop operands for the operator from the stack. 
		# Evaluate based on the operator and push the result back to the stack 
		# replace second word with result

operatoradd:
    lb $t8, ($s2) # add op to temp
    sb $t8, 0($s6) # store temp in stack
    addi $s6, $s6, 1 # increment new stack

	

	
	li $v0, 11
	li $a0, '\n'
	syscall
	
	
	#####
	addi $s3,$s3,-1 # pointing at empty space [num1][num2][pointr]
	lb $t5,0($s3) # get first from output stack
	addi $t5, $t5, -48 
	
	
	#$t6 holds second number
	addi $s3,$s3,-1 # add 1 to get next num
	lb $t6,0($s3) # get second num from output stack
	addi $t6, $t6, -48 
	
	add $t7,$t6,$t5 # subtract
	
	addi $t7, $t7, 48
	sb $t7,0($s3) # sub and store in output stack 
	addi $s3,$s3,1  # [res][pointr][]
	
j next 
	
operatorsub:
        
    lb $t8, ($s2) # add op to temp
    sb $t8, 0($s6) # store temp in stack
    addi $s6, $s6, 1 # increment new stack
	#####
	addi $s3,$s3,-1 # pointing at empty space [num1][num2][pointr]
	lb $t5,0($s3) # get first from output stack
	addi $t5, $t5, -48 
	
	#$t6 holds second number
	addi $s3,$s3,-1 # add 1 to get next num
	lb $t6,0($s3) # get second num from output stack
	addi $t6, $t6, -48 
	sub $t7,$t6,$t5 # subtract
	addi $t7, $t7, 48
	sb $t7,0($s3) # sub and store in output stack 
	addi $s3,$s3,1  # [res][pointr][]
j next 
	

num: # t0 is a num 
# ..a) If the element is a number, push it into the stack 

lb $t8, ($s2) # add num to temp
sb $t8,0($s5) # store temp in stack
addi $s5, $s5, 1 # increment new stack
###
sb $t0,0($s3) # store value
addi $s3,$s3,1 # [VALUE][pointr][]
j next
####





finish:

# print result, includes a '\n'
li $v0, 4
la $a0, result
syscall

li $v0, 1
addi $s3,$s3, -1 # [pointr][][] move pointer back from empty space
lb $t8, 0($s3) # print infix result
addi $t8, $t8, -48
move $a0, $t8
syscall

# print linebreak
li $v0, 11
li $a0, '\n'
syscall


li $v0, 4
la $a0, preorder
syscall

li $v0, 4
la $a0, stack3
syscall
li $v0, 4
la $a0, stack2
syscall


li $v0, 10
syscall
