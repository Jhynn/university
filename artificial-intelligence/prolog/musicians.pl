% Três músicos de uma banda multinacional executam um solo em um trecho de 
% música. Cada um toca uma única vez. O pianista toca primeiro. John toca 
% saxofone e toca antes do australiano. Mark é dos Estados Unidos e toca antes do 
% violinista. Um solista vem do Japão e um se chama Sam. Encontre quem vem de qual
% país, quem toca qual instrumento e em qual ordem.
% 
% Solução
%
% Mark      - EUA			- Piano
% John      - Japonês		- Sax
% Sam       - Australiano	- Violinista
% 
% 
% O Sam é Australiano, pois ele não pode ser o primeiro, já que o John toca antes dele
% e o Mark é dos EUA. Logo, Sam é violinista: pois não é o pianista e nem saxofonista.
% 
% John não pode ser Americano e nem Australiano, portanto ele é Japonês.
% 
% Podemos concluir que Mark é o pianista.
% 
% John toca antes do Sam, e Mark é o primeiro (e também¹ toca antes do Sam).
% Logo, a sequencia é: Mark, John e Sam.
% 
% ¹ O primeiro ─ sempre ─ toca antes do último.

seq_banda(S) :-
    S = banda(Solista1, _, _),  % Adiciona o primeiro membro na banda.
    toca(Solista1, piano),      % O pianista.
    nome(X, john),              % John é
    toca(X, saxofone),          % o saxofonista.
    tocaAntes(X, Y, S),         % E toca antes
    pais(Y, austrália),         % do austráliano
    nome(A, mark),              % Mark é 
    pais(A, eua),               % o americano.
    tocaAntes(A, B, S),         % E toca antes do violinista, pois é o primeiro.
    toca(B, violino),
    membro(U, S),               % Mais um membro é adicionado
    pais(U, japão),             % o que vem do Japão.
    membro(V, S),               % E o outro que
    nome(V, sam).               % se chama Sam.

nome(solista(Nome, _, _), Nome).
pais(solista(_, Pais, _), Pais).
toca(solista(_, _, Inst), Inst).

tocaAntes(B, C, banda(_, B, C)).  % O segundo toca antes do último.
tocaAntes(A, C, banda(A, _, C)).  % E o primeiro também toca antes do último.

membro(B, banda(_, B, _)).        % Essa regra adiciona o o segundo membro.
membro(C, banda(_, _, C)).        % E essa o terceiro.

