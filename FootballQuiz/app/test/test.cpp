#include "../game/quiz.hpp"
#include "../game/quiz.cpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>

using namespace sf;

bool mockLoadFromFile(sf::Texture& texture, const std::string& filename)
{
    return texture.create(100, 100); // Создание фиктивной текстуры размером 100x100
}

// Переопределение функции загрузки текстуры для тестирования
void mockPlayerLib()
{
    mockLoadFromFile(messitexture, "app/players/messi.jpg");
    mockLoadFromFile(mbappetexture, "app/players/mbappe.jpg");
    mockLoadFromFile(noyertexture, "app/players/noyer.jpg");
    mockLoadFromFile(neymartexture, "app/players/neymar.jpg");
    mockLoadFromFile(akinfeevtexture, "app/players/akinfeev.jpg");
    mockLoadFromFile(bufontexture, "app/players/bufon.jpg");
    mockLoadFromFile(modrictexture, "app/players/modric.jpg");
    mockLoadFromFile(oblaktexture, "app/players/yan_oblak.jpg");
    mockLoadFromFile(suarestexture, "app/players/suares.jpg");
    mockLoadFromFile(zlatantexture, "app/players/zlatan.jpg");

    oblaksprite.setTexture(oblaktexture);
    suaressprite.setTexture(suarestexture);
    zlatansprite.setTexture(zlatantexture);
    messiprite.setTexture(messitexture);
    mbappesprite.setTexture(mbappetexture);
    noyersprite.setTexture(noyertexture);
    neymarsprite.setTexture(neymartexture);
    akinfeevsprite.setTexture(akinfeevtexture);
    bufonsprite.setTexture(bufontexture);
    modricsprite.setTexture(modrictexture);
}

void mockClubLib()
{
    mockLoadFromFile(BarcelonaT, "app/club/barcelona.png");
    mockLoadFromFile(BavariaT, "app/club/bayern-munich.png");
    mockLoadFromFile(BorissaT, "app/club/borussia.png");
    mockLoadFromFile(KobenhavnT, "app/club/kobenhavn.png");
    mockLoadFromFile(qingbaoT, "app/club/qingdao.png");
    mockLoadFromFile(RealT, "app/club/real-madrid.png");
    mockLoadFromFile(salzburgT, "app/club/salzburg.png");
    mockLoadFromFile(santosT, "app/club/santos.png");
    mockLoadFromFile(spartakT, "app/club/spartak.png");
    mockLoadFromFile(torontoT, "app/club/toronto.png");

    BarcelonaS.setTexture(BarcelonaT);
    BavariaS.setTexture(BavariaT);
    BorissaS.setTexture(BorissaT);
    KobenhavnS.setTexture(KobenhavnT);
    qingbaoS.setTexture(qingbaoT);
    RealS.setTexture(RealT);
    salzburgS.setTexture(salzburgT);
    santosS.setTexture(santosT);
    spartakS.setTexture(spartakT);
    torontoS.setTexture(torontoT);
}

TEST(WinFunctionTest, WinCondition)
{
    poswin = 2;
    checkwin = 2;
    ret = 0;
    kol_vo = 0;

    int result = win();
    ASSERT_EQ(result, 2);
    ASSERT_EQ(kol_vo, 1);
}

TEST(WinFunctionTest, IncorrectAnswer)
{
    poswin = 1;
    checkwin = 3;
    ret = 0;
    kol_vo = 0;

    int result = win();
    ASSERT_EQ(result, 1);
    ASSERT_EQ(kol_vo, 0);
}

TEST(WinFunctionTest, InvalidInput)
{
    poswin = 100;
    checkwin = 2;
    ret = 0;
    kol_vo = 0;

    int result = win();
    ASSERT_EQ(result, 0);
    ASSERT_EQ(kol_vo, 0);
}

TEST(PlayerLibTest, TexturesLoadCorrectly)
{
    playerlib();
    ASSERT_TRUE(messitexture.getSize().x > 0);
    ASSERT_TRUE(mbappetexture.getSize().x > 0);
    ASSERT_TRUE(noyertexture.getSize().x > 0);
    ASSERT_TRUE(neymartexture.getSize().x > 0);
    ASSERT_TRUE(akinfeevtexture.getSize().x > 0);
    ASSERT_TRUE(bufontexture.getSize().x > 0);
    ASSERT_TRUE(modrictexture.getSize().x > 0);
    ASSERT_TRUE(oblaktexture.getSize().x > 0);
    ASSERT_TRUE(suarestexture.getSize().x > 0);
    ASSERT_TRUE(zlatantexture.getSize().x > 0);
}

TEST(ClubLibTest, TexturesLoadCorrectly)
{
    clublib();
    ASSERT_TRUE(BarcelonaT.getSize().x > 0);
    ASSERT_TRUE(BavariaT.getSize().x > 0);
    ASSERT_TRUE(BorissaT.getSize().x > 0);
    ASSERT_TRUE(KobenhavnT.getSize().x > 0);
    ASSERT_TRUE(qingbaoT.getSize().x > 0);
    ASSERT_TRUE(RealT.getSize().x > 0);
    ASSERT_TRUE(salzburgT.getSize().x > 0);
    ASSERT_TRUE(santosT.getSize().x > 0);
    ASSERT_TRUE(spartakT.getSize().x > 0);
    ASSERT_TRUE(torontoT.getSize().x > 0);
}

TEST(QuizplayerTest, ValidTruePlayer)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Quizplayer();
    ASSERT_TRUE(checkwin >= 0 && checkwin < 4);
    ASSERT_TRUE(positions[checkwin] == 2);
    ASSERT_TRUE(posnames[checkwin] == names[TruePlayer]);
}

TEST(QuizplayerTest, ValidFalsePlayers)
{
    srand(time(nullptr));
    Quizplayer();
    for (int i = 0; i < 4; ++i) {
        if (i != checkwin) {
            ASSERT_NE(posnames[i], names[TruePlayer]);
        }
    }
}

TEST(LibraryTest, PlayerLibTexturesLoad)
{
    mockPlayerLib();

    // Проверка установки текстур
    EXPECT_EQ(messiprite.getTexture(), &messitexture);
    EXPECT_EQ(mbappesprite.getTexture(), &mbappetexture);
    EXPECT_EQ(noyersprite.getTexture(), &noyertexture);
    EXPECT_EQ(neymarsprite.getTexture(), &neymartexture);
    EXPECT_EQ(akinfeevsprite.getTexture(), &akinfeevtexture);
    EXPECT_EQ(bufonsprite.getTexture(), &bufontexture);
    EXPECT_EQ(modricsprite.getTexture(), &modrictexture);
    EXPECT_EQ(oblaksprite.getTexture(), &oblaktexture);
    EXPECT_EQ(suaressprite.getTexture(), &suarestexture);
    EXPECT_EQ(zlatansprite.getTexture(), &zlatantexture);
}

TEST(LibraryTest, ClubLibTexturesLoad)
{
    mockClubLib();

    // Проверка установки текстур
    EXPECT_EQ(BarcelonaS.getTexture(), &BarcelonaT);
    EXPECT_EQ(BavariaS.getTexture(), &BavariaT);
    EXPECT_EQ(BorissaS.getTexture(), &BorissaT);
    EXPECT_EQ(KobenhavnS.getTexture(), &KobenhavnT);
    EXPECT_EQ(qingbaoS.getTexture(), &qingbaoT);
    EXPECT_EQ(RealS.getTexture(), &RealT);
    EXPECT_EQ(salzburgS.getTexture(), &salzburgT);
    EXPECT_EQ(santosS.getTexture(), &santosT);
    EXPECT_EQ(spartakS.getTexture(), &spartakT);
    EXPECT_EQ(torontoS.getTexture(), &torontoT);
}
