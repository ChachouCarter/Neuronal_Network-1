#include "OutputLayer.hpp"


// Constructeur
OutputLayer::OutputLayer(int sizeIn, int sizeOut) : Proba(10,1)
{
    tailleInput = sizeIn;
    tailleOutput = sizeOut;
    result = -1;
}

void OutputLayer::creer_derniere_couche(int tailleInput, int tailleOutput, TrainingFunction f)
{
    Matrix poids = Matrix(10,1);
    poids.creerGaussien(0,1); //loi normale centrée réduite

}

void OutputLayer::fonction_de_perte()
{
}

void OutputLayer::enregistrer_vecteur_de_probabilite(Layer L)
{
}

void OutputLayer::obtenir_resultat()
{
}

// destructeur
OutputLayer::~OutputLayer()
{
}
