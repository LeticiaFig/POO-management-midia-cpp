#ifndef Midia_HPP
#define Midia_HPP

#include <iostream>
#include <vector>

using namespace std;

class Midia
{
  string titulo;
  vector<string> artistas;
  int data;
  int duracao;
  vector<string> keywords;
  int numeroAcessos;

public:
  Midia()
  {
    vector<string> artistas;
    vector<string> keywords;
    setTitulo(".");
    setArtistas(artistas);
    setData(0);
    setDuracao(0);
    setKeywords(keywords);
    setNumeroAcessos(0);
  }

  Midia(string titulo, vector<string> artistas, int data, int duracao, vector<string> keywords, int numeroAcessos)
  {
    setTitulo(titulo);
    setArtistas(artistas);
    setData(data);
    setDuracao(duracao);
    setKeywords(keywords);
    setNumeroAcessos(numeroAcessos);
  }

  void setTitulo(string titulo)
  {
    this->titulo = titulo; // O this é importante para acessar o membro da classe
  }
  string getTitulo()
  {
    return this->titulo; // Lembra disso
  }

  void setArtistas(vector<string> artistas)
  {
    this->artistas = artistas;
  }
  vector<string> getArtistas()
  {
    return this->artistas;
  }

  void setData(int data)
  {
    this->data = data;
  }
  int getData()
  {
    return this->data;
  }
  int getAno()
  {
    return this->data % 10000;
  }

  void setDuracao(int duracao)
  {
    this->duracao = duracao;
  }
  int getDuracao()
  {
    return this->duracao;
  }

  void setKeywords(vector<string> keywords)
  {
    this->keywords = keywords;
  }
  vector<string> getKeywords()
  {
    return this->keywords;
  }

  void setNumeroAcessos(int numeroAcessos)
  {
    this->numeroAcessos = numeroAcessos;
  }
  int getNumeroAcessos()
  {
    return this->numeroAcessos;
  }
  void incrementNumeroAcessos(int numeroAcessos)
  {
    this->numeroAcessos = getNumeroAcessos() + numeroAcessos;
  }
};

#endif