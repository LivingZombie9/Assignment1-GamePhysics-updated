#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	TextureManager::Instance()->draw("background2", 400, 300, 0, 255, true);

	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	TextureManager::Instance()->load("../Assets/textures/Background2.png", "background2");

	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color red = { 255, 0, 0, 255 };

	m_pStartLabel = new Label("ASSIGNMENT 1", "Consolas", 80, blue, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("Press 1 to Play", "Consolas", 40, blue, glm::vec2(400.0f, 120.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	m_pNamesLabel = new Label("Eisen Enrique", "Consolas", 20, red, glm::vec2(400.0f, 200.0f));
	m_pNamesLabel->setParent(this);
	addChild(m_pNamesLabel);
	m_pNamesLabel = new Label("101244409", "Consolas", 10, red, glm::vec2(400.0f, 215.0f));
	m_pNamesLabel->setParent(this);
	addChild(m_pNamesLabel);

	m_pNamesLabel = new Label("Lisbeth Belanger", "Consolas", 20, red, glm::vec2(200.0f, 200.0f));
	m_pNamesLabel->setParent(this);
	addChild(m_pNamesLabel);
	m_pNamesLabel = new Label("101236324", "Consolas", 10, red, glm::vec2(200.0f, 215.0f));
	m_pNamesLabel->setParent(this);
	addChild(m_pNamesLabel);

	m_pNamesLabel = new Label("Abel Moore", "Consolas", 20, red, glm::vec2(600.0f, 200.0f));
	m_pNamesLabel->setParent(this);
	addChild(m_pNamesLabel);
	m_pNamesLabel = new Label("101156682", "Consolas", 10, red, glm::vec2(600.0f, 215.0f));
	m_pNamesLabel->setParent(this);
	addChild(m_pNamesLabel);

	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(400.0f, 500.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	
}

