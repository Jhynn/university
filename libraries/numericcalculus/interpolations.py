#!/usr/bin/python3


def polinomial_interpolation(points: tuple) -> list:
    '''Interpola um conjundo de dados,
    usando o método da Interpolação Polinomial.'''
    equations = list()
    polynomial_degree = len(points) - 1
    literal = 97           # chr(97) == 'a'.
    k = polynomial_degree  # Maior grau possivel.

    # #### #### #### #### Construindo o sistema de equações #### #### #### ####
    for j in range(polynomial_degree+1):
        aux = list()
        for i in range(polynomial_degree+1):
            # aux.append(chr(literal))  # Adiciona a literal.
            # literal += 1              # Avança para a proxima literal.
            aux.append(points[j][0])  # O valor x é adicionado. (X, y)
        aux.append(points[j][1])      # Por último o valor y.   (x, Y)
        equations.append(aux)         # A equação é adicionada no SE.
        # literal = 97                  # E a literal volta a ser 'a'.

    for l in range(len(equations)):
        for m in range(len(equations[0])-1):  # 1, 2
            # O coeficiente é elevado a potência adequada.
            equations[l][m] = equations[l][m]**k
            k -= 1             # Expoente diminui, a cada interação.
        k = polynomial_degree  # E, depois, volta a ser o maior possivel.

    # #### #### #### #### #### #### Subtrações... #### #### #### #### #### ####

    solution = list()
    z = len(equations[0])
    counter = len(equations)
    previous_equations = list()

    while counter > 1:
        previous_equations.append(equations[0])
        for i in range(len(equations)-1):
            aux = list()
            for j in range(z):
                aux.append(equations[i+1][j] - equations[i][j])
            solution.append(aux)
        equations = solution
        solution = list()
        counter -= 1

    # print(equations)
    # print(previous_equations)
    need_simplify = False

    for i in range(1, len(equations[0])-1):
        if equations[0][i] != 0:
            need_simplify = True
            break

    while need_simplify:
        aux = list()
        for i, j in zip(equations[len(equations)-1],
                        previous_equations[len(previous_equations)-1]):
            aux.append(i-j)

        equations = aux

        for i in range(1, len(equations)-1):
            if equations[i] == 0:
                need_simplify = False

    # verificar se a previous tem valores repetidos

    # Sobreescrever o solution com a solução.
    # print(equations)
    solution.append(equations[0][len(equations[0])-1] / equations[0][0])
    incognita = 0

    while len(solution) != polynomial_degree+1:
        for i in range(len(solution)):
            incognita += solution[i] * previous_equations[-1][i]
            if i == len(solution)-1:
                incognita = (
                    previous_equations[-1][-1] - incognita) \
                    / previous_equations[-1][i+1]
                solution.append(incognita)
                previous_equations.pop()
                incognita = 0

    return solution


def Gerador(solution, point):
    polinomial_degree = len(solution)-1
    result = 0.0
    for i in range(len(solution)):  # 1, 2
        # O coeficiente é elevado a potência adequada.

        print(point**polinomial_degree * solution[i])
        if i == len(solution):
            result += solution[i]
        else:
            result += (point**polinomial_degree) * solution[i]
        polinomial_degree -= 1            # Expoente diminui, a cada interação.
    print(result)


allpoints = (0, 2.34), (1, 3.40), (2, 5.01), (3, 5.54), (4, 4.09), (5, 3.25), \
    (6, 4.32), (7, 3.39), (8, 5.73), (9, 5.68), (10, 4.29), (11, 3.99), \
    (12, 3.54), (13, 4.40), (14, 3.68), (15, 4.18), (16, 4.38), \
    (17, 5.27), (18, 5.16), (19, 4.86), (20, 8.35), (21, 9.12), (22, 10.6), \
    (23, 10.1), (24, 11.0), (25, 12.2), (26, 13.7), (27, 12.4), (28, 11.5), \
    (29, 12.2), (30, 13.1), (31, 14.01), (32, 16.61), (33, 18.78), \
    (34, 22.45), (35, 20.29)

equations = polinomial_interpolation(allpoints)

# print(equations)
Gerador((2, 2, 2, 2, 2), 3)
# import_dados()
# (3, 6), (4, 7), (5, 12), (6, 16)

# print('Equation = [', end='')
# for element in equations:
#    print(element,',', end='')

# print(']')
