class Cartesian(object):
    '''A coordinate of a point with Cartesian System.'''

    def __init__(self, width, height=None, depth=None):
        if isinstance(width, Cartesian):
            self.__width = width.width
            self.__depth = width.depth
            self.__height = width.height
            return
        elif not isinstance(width, (int, float)) \
                or not isinstance(height, (int, float)) \
                or not isinstance(depth, (int, float)):
            raise TypeError('The coordinates must be numbers \
                or another Cartesian.')
        self.__width = width
        self.__depth = depth
        self.__height = height

    @property
    def width(self) -> (int, float):
        return self.__width

    @width.setter
    def width(self, width):
        if not isinstance(width, (int, float)):
            raise TypeError('The argument must be a number.')
        self.__width = width

    @property
    def depth(self) -> (int, float):
        return self.__depth

    @depth.setter
    def depth(self, depth):
        if not isinstance(depth, (int, float)):
            raise TypeError('The argument must be a number.')
        self.__depth = depth

    @property
    def height(self) -> (int, float):
        return self.__height

    @height.setter
    def height(self, height):
        if not isinstance(height, (int, float)):
            raise TypeError('The argument must be a number.')
        self.__height = height

    def clone(self):
        return Cartesian(self)

    def __repr__(self):
        return 'Cartesian(%g, %g, %g)' % (self.width, self.height, self.depth)

    def __str__(self):
        return 'Width  (x): %g\nHeight (y): %g\nDepth  (z): %g' \
            % (self.width, self.height, self.depth)

    def move(self, x, y=None, z=None):
        if isinstance(x, Cartesian):
            self.width += x.width
            self.height += x.height
            self.depth += x.depth
        elif not isinstance(x, (int, float)) \
                or not isinstance(y, (int, float)) \
                or not isinstance(z, (int, float)):
            raise TypeError('The values must be numbers.')
        else:
            self.width += x
            self.height += y
            self.depth += z

    def __add__(self, another_point):
        if not isinstance(another_point, Cartesian):
            raise TypeError('The argument must be a Cartesian.')
        return Cartesian(self.width + another_point.width,
                         self.height + another_point.height,
                         self.depth + another_point.depth)

    def __neg__(self):
        return Cartesian(self.width * - 1, self.height * - 1, self.depth * - 1)

    def __sub__(self, another_point):
        return self + (-another_point)

    def __mul__(self, another_point):
        if isinstance(another_point, Cartesian):
            return Cartesian(self.width*another_point.width,
                             self.height*another_point.height,
                             self.depth*another_point.depth)

        elif isinstance(another_point, (int, float)):
            return Cartesian(self.width*another_point,
                             self.height*another_point,
                             self.depth*another_point)
        else:
            raise TypeError('The argument must be a Cartesian or a constant.')

    def __rmul__(self, constant):
        return self * constant

    def __eq__(self, another_point):
        if not isinstance(another_point, Cartesian):
            raise TypeError('The member must be a Cartesian.')
        return self.width == another_point.width\
            and self.height == another_point.height\
            and self.depth == another_point.depth

    def __ne__(self, another_point):
        return not (self == another_point)


try:
    a = Cartesian(7, 9, 4.8)
    print('A')
    print(a)
    b = a.clone()

    print('\nB (Move)')
    b.move(1, 8, 7.9)
    b.width = 1
    print(b)

    print("\nMult")
    print(a*b)
    print()
    print(a)
    print()
    print(3*a)

    print('\nEqual')
    print(a == b)
except TypeError as identifier:
    print(identifier)
except Exception:
    print("Sorry, I don't know what happens!")
