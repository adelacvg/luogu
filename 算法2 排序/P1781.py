n = int(input())
l = [int(input()) for _ in range(n)]
index,value=max(enumerate(l),key=lambda x:x[1])
print(index+1)
print(value)
