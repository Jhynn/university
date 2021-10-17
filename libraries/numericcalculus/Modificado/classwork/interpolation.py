def polinomial_interpolation(points) -> tuple:
    linear_equations = list()
    polynomial_degree = len(points) - 1
    literal = 97  # chr(97) == 'a'.
    k, l, m = 0, 0, polynomial_degree

    # Gerando as equações.
    for i in range(polynomial_degree+1):
        linear_equations.append(list())
        for j in range(polynomial_degree+1):
            linear_equations[i].append(
                (literal, points[j][1], m)
            )
            literal += 1
            m -= 1
        m = polynomial_degree

    return linear_equations


points = [(1, -29), (2, -87), (7, 205)]  # (x, y)
le = polinomial_interpolation(points)
for e in le:
    print(le)
