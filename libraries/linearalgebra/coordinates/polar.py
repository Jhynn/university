class Polar(object):
    def __init__(self, radial, angular):
        if isinstance(radial, Polar):
            self.radial = radial.radial
            self.angular = radial.angular
        elif isinstance(radial, (int, float)) and\
                isinstance(angular, (int, float)):
            print("Radial", radial)
            self.__radial = radial
            self.angular = angular
        else:
            raise TypeError('You must to pass a radial coordinate and a\
                angular coordinate or another Polar Coordinate.')

    @property
    def radial(self) -> float:
        return self.__angular

    @radial.setter
    def radial(self, intensity):
        if not isinstance(intensity, (int, float)):
            raise TypeError('The argument must be a number.')
        self.__radial = intensity

    @property
    def angular(self) -> float:
        return self.__angular

    @angular.setter
    def angular(self, angle):
        if not isinstance(angle, (int, float)):
            raise TypeError('The argument must be a number.')
        self.__angular = self.__correct_angle(angle)

    def __correct_angle(self, angle) -> float:
        '''Returns the correct angle.'''
        if (angle > 360):
            decimals = abs(angle) - int(abs(angle))
            angle = int(angle % 360)
            angle += decimals
        return angle

    def __repr__(self):
        return 'Polar(%g, %gº)' % (self.radial, self.angular)


try:
    p = Polar(5, 361)
    print(p)
except TypeError as identifier:
    print(identifier)
