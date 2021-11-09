#!/usr/bin/python3

from deck import Deck
# Alinne Grazielle e Matheus Miranda.

deck = Deck()

while len(deck.deck) > 1:
    try:
        n = int(input("Enter the number of cards to be removed: "))
        deck.remove(n)
        deck.show()
    except IndexError:
        print("Please, type other value (max: %d)." % (len(deck.deck)))
    except TypeError:
        print("You must type only numbers.")
    except Exception:
        print("Sorry, I don't know what happens. So, please try again!")
print("Game over!")
