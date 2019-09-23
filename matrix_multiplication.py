import numpy
import time


# testing it on python
def matrix_v1(A, B):  # non recursive
    # 어차피 M1하고 M2는 크기가 같으니까 M1 길이로 초기화 시킴
    N = len(A[0])
    C = numpy.zeros(shape=(N, N))
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    return C


def matrix_v2(A, B):  # recursively
    N = A.shape[0]
    C = numpy.zeros(shape=(N, N))
    if N == 1:
        C[0][0] = A[0][0] * B[0][0]
    else:
        partition = N // 2
        C[:partition, :partition] = matrix_v2(A[:partition, :partition], B[:partition, :partition]) + matrix_v2(
            A[:partition, partition:], B[partition:, :partition])

        C[:partition, partition:] = matrix_v2(A[:partition, :partition], B[:partition, partition:]) + matrix_v2(
            A[:partition, partition:], B[partition:, partition:])

        C[partition:, :partition] = matrix_v2(A[partition:, :partition], B[:partition, :partition]) + matrix_v2(
            A[partition:, partition:], B[partition:, :partition])

        C[partition:, partition:] = matrix_v2(A[partition:, :partition], B[:partition, partition:]) + matrix_v2(
            A[partition:, partition:], B[partition:, partition:])
    return C


if __name__ == "__main__":
    matrix1 = numpy.random.randint(0, 10, size=(1024, 1024))
    matrix2 = numpy.random.randint(0, 10, size=(1024, 1024))
    start = time.time()
    print(matrix_v1(matrix1, matrix2))
    print("matrix_v1 time :", time.time() - start)
    start = time.time()
    print(matrix_v2(matrix1, matrix2))
    print("matrix_v2 time :", time.time() - start)