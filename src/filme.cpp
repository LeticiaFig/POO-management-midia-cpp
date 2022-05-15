#ifndef Filme_CPP
#define Filme_CPP

#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

void printFilmesList(vector<Filme> filmes)
{
  if (filmes.size() == 0)
  {
    cout << endl
         << "Nenhum filme para ser listado" << endl;
    return;
  }

  cout << "___________________________________________" << endl
       << "\tLista de filmes: " << endl
       << endl
       << "    Titulo \tAno de lançamento"
       << endl;

  for (size_t i = 0; i < filmes.size(); i++)
  {
    cout << "(" << i + 1 << ") " << filmes[i].getTitulo() << "\t" << filmes[i].getData() % 10000 << endl;
  }

  cout << "___________________________________________" << endl;
}

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

void listFilmesByTitulo(vector<Filme> filmes)
{
  sort(filmes.begin(), filmes.end(), [](Filme &filme1, Filme &filme2)
       { return filme1.getTitulo() < filme2.getTitulo(); });
  printFilmesList(filmes);
}

void listFilmesOrderByData(vector<Filme> filmes)
{
  sort(filmes.begin(), filmes.end(), [](Filme &filme1, Filme &filme2)
       { return filme1.getData() < filme2.getData(); });
  printFilmesList(filmes);
}

void listFilmesByData(vector<Filme> filmes, int anoDeLancamento)
{
  vector<Filme> filteredFilmesByYear;
  copy_if(filmes.begin(), filmes.end(), back_inserter(filteredFilmesByYear), [&](Filme &filme)
          { return filme.getData() % 10000 == anoDeLancamento; });

  listFilmesByTitulo(filteredFilmesByYear);
}

void listArtistasByFilmes(vector<Filme> filmes)
{
  vector<string> artistas;
  for (int i = 0; i < filmes.size(); i++)
  {
    vector<string> art = filmes[i].getArtistas();
    artistas.insert(artistas.end(), art.begin(), art.end());
  }

  sort(artistas.begin(), artistas.end());
  artistas.erase(unique(artistas.begin(), artistas.end()), artistas.end());

  printArtistasFilmeList(artistas);
}

#endif