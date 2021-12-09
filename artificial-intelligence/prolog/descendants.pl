mulher(ada).
mulher(aline).
mulher(vitoria).
mulher(camila).
mulher(angra).
mulher(lana).
mulher(morgana).
mulher(isis).
mulher(lavinia).
mulher(morticia).

mae(morticia, ada).					% Descedência direta.
mae(morticia, lana).
mae(ada, isis).
mae(ada, lavinia).
mae(lana, aline).

mae(lana, vitoria).
mae(lavinia, morticia).
mae(vitoria, morgana).
mae(angra, camila).
mae(aline, morticia).

vo(X,Y) :- mae(X, Z), mae(Z, Y).	% Descedência indireta.
