#! note
import numpy as np


if __name__ == '__main__':
    main()


def main():
    a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("a:\n", a)
    b = np.array(a)
    bb = np.array(a, dtype=float)
    b = bb
    zb = np.zeros((5, 6), dtype=float)
    b = zb
    ob = np.ones((5, 6), dtype=int)
    b = ob
    eb = np.empty((5, 6), dtype=int)
    b = eb
    ab = np.arange(11, 21, 1)
    b = ab
    pb = range(11, 21, 1)
    rb = np.arange(11, 21, 1).reshape(2, 5)
    b = rb
    lb = np.linspace(1, 10, 40)
    b = lb
    print("pb:", list(pb))
    print("b:\n", b)
    print("ndim:", b.ndim)
    print("shape:", b.shape)
    print("size:", b.size)
