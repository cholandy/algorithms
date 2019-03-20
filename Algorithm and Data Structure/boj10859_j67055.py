import math

n = int(input())

def issosu(x):
	
	if (x == -1) | (x == 1):
		return False

	if x == 2:
		return True
		
	if not x%2:
		return  False
		
	for i in range(3, math.floor(math.sqrt(x)) + 1, 2):
		if not x%i:
			return False
			
	return True

def rev(x):
	x = str(x)
	r = ''
	for i in range(len(x) - 1, -1, -1):
		if (x[i] == '3') | (x[i] == '4') | (x[i] == '7'):
			return -1
		elif x[i] == '0':
			r += '0'
		elif x[i] == '1':
			r += '1'
		elif x[i] == '2':
			r += '2'
		elif x[i] == '5':
			r += '5'
		elif x[i] == '6':
			r += '9'
		elif x[i] == '8':
			r += '8'
		elif x[i] == '9':
			r += '6'
	return int(r)
	
if issosu(rev(n)) & issosu(n):
	print('yes')
else:
	print('no')