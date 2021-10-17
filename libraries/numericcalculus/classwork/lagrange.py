#!/usr/bin/python3
from copy import deepcopy


def lagrange_polynomial(points: tuple) -> tuple:
    '''Generates a polynomial function from Lagrange's polynomials.'''
    lagrange_solution = list()
    exponent = len(points)-1

# #### #### #### #### Produtos notáveis (distribuir os termos). #### #### ####

    for i in range(len(points)):          # Quantidade de equações.
        Li = list()
        for j in range(len(points)-1):    # Quantidade de operandos.
            num, den = 1, 1
            for k in range(len(points)):  # Cada termo percorre.
                # #### #### #### #### Denominador. #### #### #### #### ####
                ki = points[i][0]
                if i == k:
                    continue
                ki -= points[k][0]
                den *= ki
                # num = -(points[k][0])  # Numerador, provavelmente é aqui!
                # está mudando ao invés de ficar, somente, com o próximo!

            # #### #### #### #### #### Numerador. #### #### #### #### ####

            # # Só falta colocar o num como o próximo, diferente do ki.

            # next_i = float()
            # if j == 0:
            #     num = 1
            # elif i+1 != len(points):
            #     next_i = -(points[i+1][0])
            #     num = (next_i+num) + (num*next_i)
            # else:
            #     num = -(points[0][0])
            #     next_i = -(points[i-1][0])
            #     num = (next_i+num) + (num*next_i)
            Li.append(num/den)  # Adiciona o coeficiente.
        lagrange_solution.append(Li)

    print("\nAssumption.")
    for e in lagrange_solution:
        print(e)

    print("\nCorrect!")

    lagrange_solution = [  # É como a lista deve ficar.
        [1/12, -4/12],
        [-1/8, 2/8, 1],
        [1/24, 2/24],
    ]

    for e in lagrange_solution:
        print(e)
    print()

# #### #### #### #### Multiplicando cada coeficiente Li por Yi. #### #### ####

    aux = deepcopy(lagrange_solution)
    for i in range(len(lagrange_solution)):
        for j in range(len(lagrange_solution[i])):
            aux[i][j] = lagrange_solution[i][j] * points[i][1]

# #### #### #### #### Somando os termos de mesmo grau. #### #### ####

    lagrange_solution.clear()
    const = float()

    for i in range(len(aux)):
        while len(aux[i]) < len(points):
            # Deixa todos do mesmo tamanho para transpor.
            aux[i].append(0)
        for j in range(len(aux)):
            const += aux[j][i]
        polynomium = (const, exponent)
        exponent -= 1
        lagrange_solution.append(polynomium)
        const = 0.0

    return tuple(lagrange_solution)


def prediction_from_lagrange(lagrange_polynomial: list, arg: float) -> float:
    '''Returns a number that says the tendency of the value.'''
    prediction = float()
    # lagrange_polynomial[coefficient][exponent]
    limit = len(lagrange_polynomial)

    for i in range(limit):
        prediction += lagrange_polynomial[i][0] \
            * arg ** lagrange_polynomial[i][1]
    return prediction


all_points = (0, 2.34), (1, 3.4), (2, 5.01), (3, 5.54), (4, 4.09), (5, 3.25), \
    (6, 4.32), (7, 3.39), (8, 5.73), (9, 5.68), (10, 4.29), (11, 3.99), \
    (12, 3.54), (13, 4.4), (14, 3.68), (15, 4.18), (16, 4.38), (17, 5.27), \
    (18, 5.16), (19, 4.86), (20, 8.35), (21, 9.12), (22, 10.6), (23, 10.1), \
    (24, 11.0), (25, 12.2), (26, 13.7), (27, 12.4), (28, 11.5), (29, 12.2), \
    (30, 13.1), (31, 14.01), (32, 16.61), (33, 18.78), (34, 22.45), (35, 20.29)

points = (-2, 2), (0, -2), (4, 1),  # (10, 33), (12, 51)
polynomium = lagrange_polynomial(points)
n_point = 12

print(polynomium)
print("The prediction of l(%g) is %g."
      % (n_point, prediction_from_lagrange(polynomium, n_point)))
