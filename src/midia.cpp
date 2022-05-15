#include <iostream>
#include <algorithm>

#include "headers/musica.hpp"
#include "headers/filme.hpp"

#include "filme.cpp"
#include "musica.cpp"

#include <vector>
using namespace std;

void listAllByTitulo(vector<Filme> filmes, vector<Musica> musicas)
{
  listMusicasByTitulo(musicas);
  listFilmesByTitulo(filmes);
}

void listAllByData(vector<Filme> filmes, vector<Musica> musicas, int anoDeLancamento)
{
  listMusicasByData(musicas, anoDeLancamento);
  listFilmesByData(filmes, anoDeLancamento);
}

void listAllArtistas(vector<Filme> filmes, vector<Musica> musicas)
{
  listArtistasByMusicas(musicas);
  listArtistasByFilmes(filmes);
}