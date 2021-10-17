from math import acos, pi


class Vector(object):
    '''Vector from Linear Algebra.'''

    def __init__(self, coordinates):
        if not isinstance(coordinates, (tuple, list)):
            raise TypeError('The coordinates must be an iterable.')

        self.coordinates = tuple(coordinates)
        self.dimension = len(coordinates)

        if self.dimension == 0:
            raise ValueError('The coordinates must be nonempty.')

    def __repr__(self) -> str:
        return 'Vector{}'.format(self.coordinates)

    def __str__(self) -> str:
        return '{}'.format(self.coordinates)

    def __eq__(self, v) -> bool:
        return self.intensity == v.intensity() \
            and self.normalize() == v.normalize()

    def __ne__(self, v) -> bool:
        return not (self == v)

    def clone(self):
        return Vector(self.coordinates)

    def __add__(self, v):
        if not isinstance(v, Vector):
            raise ValueError('You must to pass a vector.')
        coordinates = [x+y for x, y
                       in zip(self.coordinates, v.coordinates)]
        return Vector(coordinates)

    def sum(self, v):
        return self + v

    def __radd__(self, v):
        return self + v

    def __neg__(self):
        return -1 * self

    def sub(self, v):
        return self - v

    def __sub__(self, v):
        return ((-v) + self)

    def times_scalar(self, k):
        if not isinstance(k, (int, float)):
            raise ValueError('The k must be a scalar.')
        coordinates = [x*k for x in self.coordinates]
        return Vector(coordinates)

    def __mul__(self, k):
        if isinstance(k, (int, float)):
            return Vector.times_scalar(self, k)
        if isinstance(k, Vector):
            return self.inner_product(k)

    def __rmul__(self, k):
        return self * k

    def __pow__(self, exp):
        if not isinstance(exp, (int)):
            raise TypeError('The exponent must be a integer number.')

        resultant = self.clone()
        for times in range(exp-1):
            resultant = self*self

        return resultant

    def intensity(self) -> float:
        '''Intensity of the vector.'''
        intensity = .0
        for k in self.coordinates:
            intensity += k**2
        # intensity = sum([coord**2 for coord in self.coordinates])
        return (intensity**.5) if (intensity > 1) else intensity

    def normalize(self):
        '''Unit vector (the direction of the vector).'''
        intensity = sum([i**2 for i in self.coordinates])
        if intensity == 0:  # Avoid division.
            raise ZeroDivisionError('Cannot normalize the zero vector.')

        intensity = intensity**.5
        return self * (1./intensity)  # Vector ÷ |Vector|

    def angle(self, vector, in_degrees=False) -> float:
        '''Angle between the vectors.'''
        radians = acos(self.normalize() * vector.normalize())

        if in_degrees:
            return radians * 180. / pi  # Degress per radians.
        return radians

    def inner_product(self, vector) -> float:
        ''''Dot Product.'''
        if not isinstance(vector, Vector):
            raise TypeError('The argument must be a Vector.')
        # self.intensity() * vector.intensity() * cos(self.angle(vector))
        return sum([x*y for x, y in zip(self.coordinates, vector.coordinates)])

    def is_orthogonal_to(self, vector, tolerance=1e-17) -> bool:
        if not isinstance(vector, Vector):
            raise TypeError('Please, enter a valid type (vector).')

        return abs(self * vector) < tolerance

    def is_zero(self, tolerance=1e-17) -> bool:
        '''Returns True whether the vector is close, less than tolerance,
        or equal to zero.'''
        return self.intensity() < tolerance

    def is_parallel_to(self, vector):
        if not isinstance(vector, Vector):
            raise TypeError('Please, enter a valid type (vector).')

        # The 0 vector is parallel (and orthogonal) to other vector.
        # (If the angle is 180º, so they are opposites to itselves).

        return self.is_zero() or vector.is_zero() or self.angle(vector) == 0 \
            or self.angle(vector) == pi

    def parallel_to(self, basis):
        '''Calculates the *component* of a parallel vector
        for a given base vector.'''
        if not isinstance(basis, Vector):
            raise TypeError('Enter a Vector.')
        u = basis.normalize()
        w = self * u  # Dot product.

        return u * w  # Times Scalar.

    def orthogonal_to(self, basis):
        '''Calculates the *component* of an orthogonal vector
        for a given base vector.'''
        if not isinstance(basis, Vector):
            raise TypeError('Enter a Vector')
        projection = self.parallel_to(basis)
        # Based, in some way, on the Pythagorean theorem.
        return self - projection

    def cross_product(self, vector):
        '''Calculates the cross product of the two vectors.'''
        if not isinstance(vector, Vector):
            raise TypeError('Please enter a Vector.')
        if self.dimension < 3 or vector.dimension < 3:
            raise ValueError('The vectors must have 3 dimensions.')

        x0, y0, z0, *w0 = self.coordinates
        x1, y1, z1, *w1 = vector.coordinates

        coordinates = [
            y0*z1 - y1*z0,
            -(x0*z1 - x1*z0),
            x0*y1 - x1*y0
        ]
        return Vector(coordinates)

    def parallelogram_area(self, vector) -> float:
        cross_product = self.cross_product(vector)
        # vector * sin() = height
        # self * vector * sin() = base * height
        return cross_product.intensity()

    def triangle_area(self, vector) -> float:
        # Half of the parallelogram.
        return self.parallelogram_area(vector) / 2.0
