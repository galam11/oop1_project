#pragma once
#include "GameObject.h"

class HideableGameObject : public GameObject
{
public:
	void hide();
	void show();
	bool isHidden() const;

private:
	bool m_hidden = false;
};
