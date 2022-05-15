#ifndef Musica_CPP
#define Musica_CPP

#include <iostream>
#include <algorithm>
#include "headers/musica.hpp"
#include <vector>

using namespace std;

void printMusicasList(vector<Musica> musicas)
{
  if (musicas.size() == 0)
  {
    cout << endl
         << "Nenhuma música para ser listada" << endl;
    return;
  }

  cout << "___________________________________________" << endl
       << "\tLista de músicas: " << endl
       << endl
       << "    Titulo \tAno de lançamento"
       << endl;

  for (size_t i = 0; i < musicas.size(); i++)
  {
    cout << "(" << i + 1 << ") " << musicas[i].getTitulo() << "\t" << musicas[i].getData() % 10000 << endl;
  }

  cout << "___________________________________________" << endl;
}

void printArtistasMusicaList(vector<string> artistas)
{
  if (artistas.size() == 0)
  {
    cout << endl
         << "Nenhum artista da música para ser listado" << endl;
    return;
  }

  cout << "___________________________________________" << endl
       << "\tLista de artistas da músicas: " << endl
       << endl;

  for (size_t i = 0; i < artistas.size(); i++)
  {
    cout << "(" << i + 1 << ") " << artistas[i] << endl;
  }

  cout << "___________________________________________" << endl;
}

void listMusicasByTitulo(vector<Musica> musicas)
{
  sort(musicas.begin(), musicas.end(), [](Musica &musica1, Musica &musica2)
       { return musica1.getTitulo() < musica2.getTitulo(); });

  printMusicasList(musicas);
}

void listMusicasOrderByData(vector<Musica> musicas)
{
  sort(musicas.begin(), musicas.end(), [](Musica &musica1, Musica &musica2)
       { return musica1.getData() < musica2.getData(); });

  printMusicasList(musicas);
}

void listMusicasByData(vector<Musica> musicas, int anoDeLancamento)
{
  vector<Musica> filteredMusicasByYear;
  copy_if(musicas.begin(), musicas.end(), back_inserter(filteredMusicasByYear), [&](Musica &musica)
          { return musica.getData() % 10000 == anoDeLancamento; });

  listMusicasByTitulo(filteredMusicasByYear);
}

void listArtistasByMusicas(vector<Musica> musicas)
{
  vector<string> artistas;
  for (int i = 0; i < musicas.size(); i++)
  {
    vector<string> art = musicas[i].getArtistas();
    artistas.insert(artistas.end(), art.begin(), art.end());
  }

  sort(artistas.begin(), artistas.end());
  artistas.erase(unique(artistas.begin(), artistas.end()), artistas.end());

  printArtistasMusicaList(artistas);
}

#endif