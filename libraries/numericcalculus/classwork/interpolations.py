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

    while counter > 1:
        print('Old size:', len(equations))
        for i in range(len(equations)-1):
            aux = list()
            for j in range(z):
                aux.append(equations[i+1][j] - equations[i][j])
            solution.append(aux)
        equations = solution
        print('New size:', len(equations))
        counter -= 1

    for j in range(len(equations[0]), 1, -1):
        equations[2].insert(j-1, chr(literal))
        literal += 1

    return equations


allpoints = (1, -29), (3, -87), (7, 205)  # (x, y)
equations = polinomial_interpolation(allpoints)

for element in equations:
    print(element)
