from decimal import Decimal
from decimal import getcontext
from vectors import Vector

getcontext().prec = 30


class Line(object):
    def __init__(self, normal_vector=None, constant_term=None):
        if not isinstance(normal_vector, Vector):
            raise TypeError('Please enter a valid type.')
        elif not isinstance(constant_term, (int, float, Decimal)):
            raise TypeError('Please enter a valid type')
        self.normal_vector = normal_vector
        self.constant_term = Decimal(constant_term)
        self.set_basepoint()

    def set_basepoint(self):
        pass
