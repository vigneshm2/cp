from math import exp, sqrt
from numpy.random import randn
import numpy as np
# from matplotlib import pyplot as plt
from scipy.stats import lognorm, norm
from time import time
from sys import stdin


def simple_price(x0, k, t, vol):
    def maxf(x):
        # return x0 * x
        return x0 * x - k
    s = vol * sqrt(t)
    mu = -s * s / 2
    return lognorm.expect(maxf, args=(s,), scale=np.exp(mu), lb=k / x0)


def simple_price2(x0, k, t, vol):
    s = vol * sqrt(t)
    mu = -s * s / 2
    scl = np.exp(mu)
    alph = (np.log(k / x0) - (mu + s * s)) / s
    p1 = x0 * (1 - norm.cdf(alph))
    p2 = k * (1 - lognorm.cdf(k / x0, s, scale=scl))
    # print(p1, p2)
    return p1 - p2


def exotic_price2(x0, k, t, vol, b):
    s = vol * sqrt(t)
    mu = -s * s / 2
    scl = np.exp(mu)
    alph = (np.log(k / x0) - (mu + s * s)) / s
    beta = (np.log(b / x0) - (mu + s * s)) / s
    p1 = x0 * (norm.cdf(beta) - norm.cdf(alph))
    p2 = k * (lognorm.cdf(b / x0, s, scale=scl) -
              lognorm.cdf(k / x0, s, scale=scl))
    # print(p1, p2)
    return p1 - p2


def search_vol(x0, k, t, price, b=None):
    lb = 1e-12
    ub = 2.0
    eps = 1e-12
    while abs(ub - lb) > eps:
        vol = (lb + ub) / 2
        if b is not None:
            pr = exotic_price2(x0, k, t, vol, b)
        else:
            pr = simple_price2(x0, k, t, vol)
        if pr < price:
            lb = vol
        elif pr > price:
            ub = vol
        else:
            return vol
    return lb


def search_inst_vol(x0, k, t, c, b=None):
    m = len(k)
    vol = [0 for _ in range(m)]
    vol[0] = search_vol(x0, k[0], t[0], c[0], b)
    for i in range(1, m):
        vol[i] = search_vol(x0, k[i], t[i] - t[i - 1], c[i], b)
    return vol


def main():
    for line in stdin:
        if line[-1] == '\n':
            line = line[:-1]
        parts = line.split(',')
        if parts[0] == '1':
            x0, k, t, c = map(float, parts[1:])
            print(search_vol(x0, k, t, c))
        elif parts[0] == '2':
            x0, k, t, b, c = map(float, parts[1:])
            vol = search_vol(x0, k, t, c)
            print(exotic_price2(x0, k, t, vol, b))
            # print(b)
        elif parts[0] == '3':
            x0 = float(parts[1])
            m = int(parts[2])
            c = list(map(float, parts[3:3 + m]))
            k = list(map(float, parts[3 + m:3 + 2 * m]))
            t = list(map(float, parts[3 + 2 * m:3 + 3 * m]))
            vols = search_inst_vol(x0, k, t, c)
            print(', '.join([str(v) for v in vols]))
        else:
            x0 = float(parts[1])
            b = float(parts[2])
            m = int(parts[3])
            c = list(map(float, parts[4:4 + m]))
            k = list(map(float, parts[4 + m:4 + 2 * m]))
            t = list(map(float, parts[4 + 2 * m:4 + 3 * m]))
            vols = search_inst_vol(x0, k, t, c, b=b)
            # print(exotic_price2(x0, k[m - 1], t[m - 1], vols[m - 1], b))
            print(c[m - 1])
            # print(c, k, t)
            # print(b)


if __name__ == '__main__':
    main()
