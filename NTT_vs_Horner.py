import time

mod = 786433
r = 10

def NTT(a,w,n):
	if(len(a) == 1):
		return [a[0]]*n
	aeven = NTT(a[0::2],w*w%mod,n//2)
	aodd = NTT(a[1::2],w*w%mod,n//2)
	x = 1
	half_n = n//2
	res = [0]*n
	for i in range(half_n):
		res[i] = (aeven[i] + x*aodd[i]%mod)%mod
		res[i+half_n] = (aeven[i]-x*aodd[i]%mod+mod)%mod
		x = x*w%mod
	return res

def calculate(a):
	ntt = NTT(a,r,mod-1)
	res = [0]*mod
	res[0] = a[0]
	x = 1
	for i in range(mod-1):
		res[x] = ntt[i]
		x = x*r%mod
	return res

from random import randint

def first_method(n,a):
	values = calculate(a)
	q = n
	for i in range(q):
		xx = 1

def second_method(n,a):
	q = n
	for i in range(n):
		x = i
		y = 0
		k = -1
		for j in range(n):
			y+=a[k]
			y*=x
			k-=1
		y= y + a[0]%mod

mm = [0.00]*10001
nn = [0.00]*10001
ii = [0]*10001
for i in range (1000,5000,100):
	n = i
	a = [0]*n
	for i in range(n):
		a[i] = randint(1,1000)
	first_start_time = time.time()
	first_method(n,a)
	second_start_time = time.time()
	print("First Algorithm ", second_start_time - first_start_time)
	second_method(n,a)
	third_start_time = time.time()
	print("Second Algorithm ",third_start_time - second_start_time)
	mm[i] = (second_start_time - first_start_time)
	nn[i] = (third_start_time - second_start_time)
	with open('m.txt', 'a') as the_m:
		the_m.write(str(mm[i]))
		the_m.write('\n')
	with open('n.txt', 'a') as the_n:
		the_n.write(str(nn[i]))
		the_n.write('\n')

	print(mm[i],nn[i])
