#include <iostream>
#include <algorithm>

#include "headers/musica.hpp"
#include "headers/filme.hpp"

#include "filme.cpp"
#include "musica.cpp"

#include <vector>
using namespace std;

template <typename T>
void printList(vector<T> objects, string str)
{
  if (objects.size() == 0)
  {
    cout << "\nNenhum(a) " << str << " para ser listado(a)\n";
    return;
  }
  cout << "___________________________________________\n"
       << "Lista de " << str << "s:\n\n"
       << "    Titulo - Ano de lancamento\n";
  for (size_t i = 0; i < objects.size(); i++)
    cout << "(" << i + 1 << ") " << objects[i].getTitulo() << " - " << objects[i].getAno() << "\n";
  cout << "___________________________________________\n";
}
template <typename T>
void listByTitulo(vector<T> objects, string str)
{
  sort(objects.begin(), objects.end(), [](T &obj1, T &obj2)
       { return obj1.getTitulo() < obj2.getTitulo(); });
  printList<T>(objects, str);
}
template <typename T>
void listByData(vector<T> objects, int anoDeLancamento, string str)
{
  vector<T> filteredObjectsByYear;
  copy_if(objects.begin(), objects.end(), back_inserter(filteredObjectsByYear), [&](T &obj)
          { return obj.getData() % 10000 == anoDeLancamento; });

  listByTitulo<T>(filteredObjectsByYear, str);
}

void listAllByTitulo(vector<Filme> filmes, vector<Musica> musicas)
{
  listByTitulo<Musica>(musicas, "musica");
  listByTitulo<Filme>(filmes, "filme");
}

void listAllByData(vector<Filme> filmes, vector<Musica> musicas, int anoDeLancamento)
{
  listByData<Musica>(musicas, anoDeLancamento, "musica");
  listByData<Filme>(filmes, anoDeLancamento, "filme");
}

void listAllArtistas(vector<Filme> filmes, vector<Musica> musicas)
{
  listArtistasByMusicas(musicas);
  listArtistasByFilmes(filmes);
}