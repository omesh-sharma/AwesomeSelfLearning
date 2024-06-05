# def solution(a,b):
#     count = 0
#     n = a*b
#     while (n):
#         count += n & 1
#         n >>= 1
#     return count


#print(solution(3,7))

# def solution(A, k):
#     if A:
#         if k in A:
#             return True
#         else:
#             return False
#     else:
#         return False

# print(solution(A=[1,1,3], k=2))

# def solution(arr):
#     b = []
#     n = len(arr)
#     for i in range(n):
#         b.append(arr[i])
         
#     b.sort()
     
#     ct = 0
#     for i in range(n):
#         if arr[i] != b[i]:
#             ct += 1
             
#     if ct == 0 or ct == 2:
#         return True
#     else:
#         return False
 
# arr = [1, 5, 3, 4, 2]
# n= len(arr)
# print(solution(arr=[1, 5, 3, 4, 2]))

# def solution(A, k):
#     n = len(A)
    
#     for i in range(n-1):
#         if (A[i] + 1  < A[i + 1]):
#             return False
#     if (A[0] != 1 or A[n-1] != k):
#         return False
#     else:
#         return True

def solution(A, K):
    n = len(A)
    for i in range(n - 1):
        if (A[i] != A[i + 1] and A[i] + 1 != A[i + 1]):
            return False
    if (A[0] != 1 or A[n - 1] != K):
        return False
    else:
        return True

print(solution([1,2,3],2))