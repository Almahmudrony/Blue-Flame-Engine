#pragma once
#include "BF/BlueFlame.h"
#include "Snake.h"
#include "Food.h"
#include "HUD.h"

class MainScene : public BF::Application::Scene
{
private:
	BF::Graphics::Camera camera;
	BF::Graphics::Renderers::SpriteRenderer spriteRenderer;

	Snake snake;
	Food food;
	HUD hud;

public:
	MainScene();
	~MainScene();

private:
	void Initialize() override;
	void Load() override;
	void Update() override;
	void Render() override;
};