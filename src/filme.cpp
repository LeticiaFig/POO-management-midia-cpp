#ifndef Filme_CPP
#define Filme_CPP

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void chooseRandomFilme(vector<Filme> filmes)
{
  if (filmes.size() == 0)
  {
    cout << "Nenhum filme cadastrado!" << endl;
    return;
  }

  int randomIndex = rand() % filmes.size();
  Filme randomFilme = filmes[randomIndex];

  cout << "Selelecionando um filme aleatório..." << endl
       << endl
       << "Filme escolhido: " << randomFilme.getTitulo() << " (" << randomFilme.getAno() << ")!!" << endl;
}

#endif