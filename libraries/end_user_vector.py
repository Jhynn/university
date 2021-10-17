#!/usr/bin/python3
from linearalgebra import Vector


try:
    u = Vector([+7.887, 4.138])
    v = Vector([-8.802, 6.776])
    print(u**2)

    print(u+v)
    print(u-v)
    print(u*v)
    print(9*v)

    w = Vector([7.350, 0.221, 5.188])
    x = Vector([2.751, 8.159, 3.985])
    print(w.angle(x, True))

    y = Vector([6, 4])
    z = Vector([3, 2])
    print(z.parallel_to(y))

    print(z.is_parallel_to(y))
    print(z.orthogonal_to(y))
    print(z.is_orthogonal_to(y))

    a = Vector((1, 2, 7, 8))
    b = Vector((3, 2, 1, 8, 5, 5, 5))
    print(b.cross_product(a))

    print(z == y)
    print(a.triangle_area(b))
    print(a.is_zero())
except ValueError:
    print('Erro de valores.')
except TypeError:
    print('Tipos não correspodentes.')
except ZeroDivisionError:
    print('Divisão por zero.')
except Exception:
    print('Desculpe, eu não sei o que houve.')
