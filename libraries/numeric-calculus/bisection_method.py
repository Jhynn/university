#!/usr/bin/python3


def bisection_method(rooting: float, root_index: float, interactions: int,
                     upper_range: float, lower_range: float = 0) -> float:
    "Determines the root of a number, using the Bisection Method."
    x, c = 0.0, 0
    while True:
        c, previous = c + 1, x
        x = (lower_range + upper_range) / 2  # Supposed solution.

        if (x**root_index - rooting) < 0:
            lower_range = x
        elif (x**root_index - rooting) > 0:
            upper_range = x

        if c == interactions:
            return x
        # if previous == x:
        #    return x


n, e = 8, 3
test = bisection_method(n, e, 21, 4, 1)
print("Raíz %dª de %d é %f" % (e, n, test))
