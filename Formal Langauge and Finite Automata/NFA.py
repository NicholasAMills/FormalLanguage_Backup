stateDiagram = [
	[[1,4], [0,1,2,4,5]],	# State 0
	[[1], [0,1,2,4]],		# State 1
	[[1,3,4], [0,1,2,5]],	# State 2
	[[0,1,2,4], [3]],		# State 3
	[[4], [5]],				# State 4				
	[[0,1,4,6], [7]],		# State 5
	[[1,4,8], [0,1,2,4,5]],	# State 6
	[[5], [0,1,4,6]],		# State 7
	[[7], [8]]]				# State 8
startStates = [0, 1, 4]
acceptingStates = set([2, 6])
inputString = "not empty"

while len(inputString) > 0:
	currentStates = set(startStates);
	inputString = raw_input("Enter a binary string: ")
	for letter in inputString:
		nextStates = set()
		if letter == '0':
			for state in currentStates:
				nextStates = nextStates.union(stateDiagram[state][0])
		elif letter == '1':
			for state in currentStates:
				nextStates = nextStates.union(stateDiagram[state][1])
		currentStates = list(nextStates)
	if len(acceptingStates.intersection(currentStates)) == 0:
		print("The string was rejected.")
	else:
		print("The string was accepted.")