/*
Copyright(c) 2016 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

//= INCLUDES =====================
#include <vector>
#include "GameObject.h"
#include "../Math/Vector3.h"
#include "../Pools/TexturePool.h"
#include "../Pools/MaterialPool.h"
#include "../Pools/MeshPool.h"
//================================

class Renderer;
class ModelLoader;

class Scene
{
public:
	Scene(TexturePool* texturePool, MaterialPool* materialPool, MeshPool* meshPool, ScriptEngine* scriptEngine, PhysicsEngine* physics, ModelLoader* modelLoader, Renderer* renderer);
	~Scene();

	void Initialize();
	void Update();

	/*------------------------------------------------------------------------------
										[I/O]
	------------------------------------------------------------------------------*/
	bool SaveToFile(std::string path);
	bool LoadFromFile(std::string path);

	/*------------------------------------------------------------------------------
										[MISC]
	------------------------------------------------------------------------------*/
	void Clear();
	GameObject* GetMainCamera();
	void SetAmbientLight(float x, float y, float z);
	Directus::Math::Vector3 GetAmbientLight();
	void MakeDirty();

	std::vector<GameObject*> GetRenderables();
	std::vector<GameObject*> GetDirectionalLights();
	std::vector<GameObject*> GetPointLights();

private:
	/*------------------------------------------------------------------------------
							[SCENE ANALYSIS]
	------------------------------------------------------------------------------*/
	void AnalyzeGameObjects();

	std::vector<GameObject*> m_renderablePool;
	std::vector<GameObject*> m_directionalLightPool;
	std::vector<GameObject*> m_pointLightPool;

	/*------------------------------------------------------------------------------
										[CREATE]
	------------------------------------------------------------------------------*/
	GameObject* CreateCamera();
	GameObject* CreateDirectionalLight();

	/*------------------------------------------------------------------------------
										[MISC]
	------------------------------------------------------------------------------*/
	GameObject* m_mainCamera;
	bool m_isDirty;
	Directus::Math::Vector3 m_ambientLight;

	TexturePool* m_texturePool;
	MaterialPool* m_materialPool;
	MeshPool* m_meshPool;
	ScriptEngine* m_scriptEngine;
	PhysicsEngine* m_physics;
	ModelLoader* m_modelLoader;
	Renderer* m_renderer;
};