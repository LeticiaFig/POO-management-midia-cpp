#ifndef Filme_CPP
#define Filme_CPP

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void printArtistasFilmeList(vector<string> artistas)
{
  if (artistas.size() == 0)
  {
    cout << endl
         << "Nenhum artista da filmes para ser listado" << endl;
    return;
  }

  cout << "___________________________________________" << endl
       << "\tLista de artistas da filmes: " << endl
       << endl;

  for (size_t i = 0; i < artistas.size(); i++)
  {
    cout << "(" << i + 1 << ") " << artistas[i] << endl;
  }

  cout << "___________________________________________" << endl;
}

void listFilmesOrderByData(vector<Filme> filmes)
{
  sort(filmes.begin(), filmes.end(), [](Filme &filme1, Filme &filme2)
       { return filme1.getData() < filme2.getData(); });
  //printList<Filme>(filmes, "filme");
}

void listArtistasByFilmes(vector<Filme> filmes)
{
  vector<string> artistas;
  for (size_t i = 0; i < filmes.size(); i++)
  {
    vector<string> art = filmes[i].getArtistas();
    artistas.insert(artistas.end(), art.begin(), art.end());
  }

  sort(artistas.begin(), artistas.end());
  artistas.erase(unique(artistas.begin(), artistas.end()), artistas.end());

  printArtistasFilmeList(artistas);
}

void countFilmesByGenero(vector<Filme> filmes)
{
  map<GenerosDeFilme, int> counter;
  vector<GenerosDeFilme> generos;

  vector<string> generoDeFilme;
  generoDeFilme.push_back("Null_MovieGenre");
  generoDeFilme.push_back("Terror");
  generoDeFilme.push_back("Suspense");
  generoDeFilme.push_back("Acao");
  generoDeFilme.push_back("Drama");
  generoDeFilme.push_back("Documentario");
  generoDeFilme.push_back("Comedia");

  for (size_t i = 0; i < filmes.size(); i++)
  {
    generos = filmes[i].getGeneroDeFilme();
    for_each(begin(generos), end(generos), [&](GenerosDeFilme const &s)
             { ++counter[s]; });
  }

  cout << endl
       << "Contagem de gêneros de filmes" << endl
       << endl;
  for (auto const &pair : counter)
  {
    cout << generoDeFilme[pair.first] << ": " << pair.second << endl;
  }
}

#endif