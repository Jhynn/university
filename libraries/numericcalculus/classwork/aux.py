#!/usr/bin/python3


def simplify(polynomial: tuple) -> tuple:
    '''Simplify a polynomial product.'''
    simplified = list()
    for i in range(len(polynomial)):
        b = False
        for j in range(len(polynomial)):
            if i == j or b:
                continue
            if polynomial[i][1] == polynomial[j][1]:
                print("Entrou!", polynomial[i])
                t = (polynomial[i][0] + polynomial[j][0], polynomial[i][1])
                simplified.append(t)
                b = True
                if (i + 2) < len(polynomial):
                    i += 2
        simplified.append(polynomial[i])
    print(polynomial)
    return simplified


def expand_polynomial(terms: tuple) -> tuple:
    '''Multiply each of the terms within the first parentheses by each of
    the terms within the second parentheses, left to right.'''
    solution = list()

    for i in range(len(terms)):
        solution.append((1, -terms[i][0]))  # (x - xn) (exp, exp)

    aux = list()
    limit = 2
    print("Old:", solution)
    while len(solution) > 1:
        for i in range(limit):
            for j in range(2):
                if i != 0:
                    exp = abs(-1+j)
                    t = (solution[0][i] * solution[1][j], exp)
                    aux.append(t)
                    if isinstance(solution[0][0], tuple) and \
                            isinstance(solution[1][0], tuple):
                        exp = abs(-1+j)  # Talvez tenha que mudar.
                        t = (solution[0][0][i] * solution[1][0][j], exp)
                        aux.append(t)
                else:  # Tudo certo!
                    exp = abs(-2+j)
                    t = (solution[0][i] * solution[1][j], exp)
                    aux.append(t)
                limit = len(aux)
        print('solution:', solution)
        # Simplificar.

        solution.pop(0)
        solution.pop(0)
        solution.insert(0, aux.copy())
        aux.clear()

    return solution[0]


p = (-2, 2), (4, 1),  # (10, 33),
solution = expand_polynomial(p)

print("Global:", simplify(solution))
