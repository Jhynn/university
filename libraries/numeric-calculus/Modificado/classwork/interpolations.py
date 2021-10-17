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
        for i in range(len(equations)-1):
            aux = list()
            for j in range(z):
                aux.append(equations[i+1][j] - equations[i][j])
            previous_equations.append(equations[0])
            solution.append(aux)
        equations = solution
        counter -= 1

    need_simplify = False
    for i in range(1, len(equations)-1):
        if equations[i] != 0:
            need_simplify = True
            break

    while need_simplify:
        aux = list()
        for i,j in zip(equations[len(equations)-1],
                        previous_equations[len(previous_equations)-1]):
            aux.append(i-j)

        equations = aux

        for i in range(1, len(equations)-1):
            if equations[i] == 0:
                need_simplify = False

    # Sobreescrever o solution com a solução.
    solution = list()
    solution.append(equations[len(equations)-1]/equations[0])

    while len(solution) != (polynomial_degree+1):
        for i in range(len(solution)):
            if i == len(solution)-1:
                solution[i] = solution[i] * previous_equations[-1][i]
                solution.append(0)

    
 
    return equations


allpoints = (1, -29), (3, -87), (7, 205)  # (x, y)
equations = polinomial_interpolation(allpoints)

for element in equations:
    print(element, end=' ')
print()
