#!/usr/bin/python3/

# Alinne Grazielle e Matheus Miranda.


class Card(object):
    def __init__(self, suit, value=None, points=None):
        if isinstance(suit, Card):
            self.suit = suit.suit
            self.card = suit.card
            self.set_points(points)
            return

        if isinstance(suit, str) and isinstance(value, (int, str)):
            self.suit = suit  # Naipe da carta.
            self.card = value  # Valor da carta.
            self.set_points(points)

    def clone(self):
        return (self)

    def set_points(self, points):
        if points is None:
            if self.card == "A":
                self.points = 1
            elif self.card == "K":
                self.points = 13
            elif self.card == "Q":
                self.points = 12
            elif self.card == "J":
                self.points = 11
            else:
                self.points = int(self.card)
        elif isinstance(points, (float, int)):
            self.points = points  # Pontos que a carta possui.
        else:
            raise TypeError("Please, type a number.")

    def __repr__(self) -> str:
        return "Card(%s of %s, points: %s)" \
            % (str(self.card, self.suit, str(self.points)))

    def __str__(self) -> str:
        return "%s%s%s" % (self.card, self.suit[0], str(self.points))

    # Compara os valores de self com another_card.
    def compare(self, another_card) -> int:
        if isinstance(another_card, Card):
            auxiliar = Card(self.suit, self.card)
            artificie = Card(another_card)
            if auxiliar.points < artificie.points:
                return -1
            elif auxiliar.points > artificie.points:
                return 1
            return 0
