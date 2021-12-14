#include "pch.h"
#include "DCAmy.h"
#include "DXAmy.h"
#include "ModelInfo.h"
#include "IniFile.hpp"

NJS_MATERIAL* TemporaryMaterialArray[] = { nullptr };

static bool ModernEyelashes = false;

extern "C" __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions & helperFunctions)
{
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
	HMODULE handle = GetModuleHandle(L"CHRMODELS_orig");
	NJS_OBJECT** ___AMY_OBJECTS = (NJS_OBJECT**)GetProcAddress(handle, "___AMY_OBJECTS");
	HMODULE DCcharacters = GetModuleHandle(L"SA1_Chars");

	ModernEyelashes = config->getBool("AmyEyelashes", "ModernEyelashes", false);

	if (ModernEyelashes)
	{
		if (DCcharacters)
		{
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->model = &attach_004B86ECm;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->sibling->model = &attach_004B84BCm;
		}

		else
		{
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->model = &attach_000119A0m;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->sibling->model = &attach_00011690m;
		}
	}

	else
	{
		if (DCcharacters)
		{
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->model = &attach_004B86EC;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->sibling->model = &attach_004B84BC;
		}

		else
		{
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->model = &attach_000119A0;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->sibling->model = &attach_00011690;
		}
	}

}

extern "C" __declspec(dllexport) const ModInfo SADXModInfo = { ModLoaderVer };