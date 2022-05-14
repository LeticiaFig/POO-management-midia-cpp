#ifndef Filme_HPP
#define Filme_HPP

#include <vector>
#include "midia.hpp"

using namespace std;

enum FormatosDeVideo
{
  Terror,
  Suspense,
  Acao,
  Drama,
  Documentario,
  Comedia
};

enum GenerosDeFilme
{
  AVI,
  MKV,
  MP4,
  FLV
};

class Filme : public Midia
{
  vector<FormatosDeVideo> formatoVideo;
  vector<GenerosDeFilme> generoFilme;

public:
  Filme(vector<FormatosDeVideo> formatoVideo, vector<GenerosDeFilme> generoFilme,
        string titulo, vector<string> artistas, int data, int duracao, vector<string> keywords, int numeroAcessos) : Midia(titulo, artistas, data, duracao, keywords, numeroAcessos)
  {
    setFormatoDeVideo(formatoVideo);
    setGeneroDeFilme(generoFilme);
  }

  void setFormatoDeVideo(vector<FormatosDeVideo> formatoVideo)
  {
    this->formatoVideo = formatoVideo;
  }
  vector<FormatosDeVideo> getFormatoDeVideo()
  {
    return this->formatoVideo;
  }

  void setGeneroDeFilme(vector<GenerosDeFilme> generoFilme)
  {
    this->generoFilme = generoFilme;
  }
  vector<GenerosDeFilme> getGeneroDeFilme()
  {
    return this->generoFilme;
  }
};

#endif