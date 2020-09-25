#!/usr/bin/python3/

from card import Card
from random import randint

# Alinne Grazielle e Matheus Miranda.


class Deck(object):
    def __init__(self):
        self.deck = list()
        # Naipe de Copas
        self.deck.append(Card("Copas", "A"))

        for card in range(2, 11):
            self.deck.append(Card("Copas", card))

        self.deck.append(Card("Copas", "J"))
        self.deck.append(Card("Copas", "Q"))
        self.deck.append(Card("Copas", "K"))

        # Naipe de Espadas.
        self.deck.append(Card("Espadas", "A"))

        for card in range(2, 11):
            self.deck.append(Card("Espadas", card))

        self.deck.append(Card("Espadas", "J"))
        self.deck.append(Card("Espadas", "Q"))
        self.deck.append(Card("Espadas", "K"))

        # Naipe de Ouros.
        self.deck.append(Card("Ouros", "A"))

        for card in range(2, 11):
            self.deck.append(Card("Ouros", card))

        self.deck.append(Card("Ouros", "J"))
        self.deck.append(Card("Ouros", "Q"))
        self.deck.append(Card("Ouros", "K"))

        # Naipe de Paus.
        self.deck.append(Card("Paus", "A"))

        for card in range(2, 11):
            self.deck.append(Card("Paus", card))

        self.deck.append(Card("Paus", "J"))
        self.deck.append(Card("Paus", "Q"))
        self.deck.append(Card("Paus", "K"))

    def show(self):
        for card in self.deck:
            print(card)

    def remove(self, quantity: int = 1):
        if not isinstance(quantity, int):
            raise TypeError("Please, type a integer value")

        if quantity > len(self.deck):
            raise IndexError("The deck is less than quantity.")

        for card in range(quantity):
            print(self.deck.pop())

    def shuffle(self):
        limit = len(self.deck)
        randomic = randint(1, len(self.deck))
        randomics = list()

        for card in range(limit):
            if randomic in randomics:
                randomic = randint(1, len(self.deck)-1)
                continue
            randomics.append(randomic)
            self.deck[card] = self.deck[randomic]

    def to_sort(self):
        self.deck = sorted(self.deck, Card("").compare())  # Não consegui.
