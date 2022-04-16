#include "pch.h"
#include "DCAmy.h"
#include "KidnappedDCclassic.h"
#include "DXAmy.h"
#include "KidnappedDXclassic.h"

NJS_MATERIAL* TemporaryMaterialArray[] = { nullptr };

static bool ModernEyelashes = false;

void Init_DCclassic()
{
	AMY_OBJECTS[32] = &objectdcc_00023300;
	AMY_MOTIONS[0] = &animationdcc_004D591C;
	*(NJS_MODEL_SADX*)0x0319F6E8 = attachdcc_02D9F6E8;
	WriteData((NJS_MOTION**)0x031C1C7C, &headdcc_motion);
};

void Init_DXclassic()
{
	AMY_OBJECTS[32] = &objectdxc_00023300;
	AMY_OBJECTS[4] = &object_000159CC;
	AMY_MODELS[1] = &attach_000159A0;
	AMY_MODELS[2] = &attach_0001C100;
	AMY_MOTIONS[0] = &___AMY_MOTIONSDXC_0;
}

void Init_DXmodern()
{
	AMY_OBJECTS[4] = &object_000159CC;
	AMY_MODELS[1] = &attach_000159A0;
	AMY_MODELS[2] = &attach_0001C100;
}

extern "C" __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions & helperFunctions)
{
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
	HMODULE handle = GetModuleHandle(L"CHRMODELS_orig");
	NJS_OBJECT** ___AMY_OBJECTS = (NJS_OBJECT**)GetProcAddress(handle, "___AMY_OBJECTS");
	NJS_MODEL** ___AMY_MODELS = (NJS_MODEL**)GetProcAddress(handle, "___AMY_MODELS");
	HMODULE DCcharacters = GetModuleHandle(L"SA1_Chars");
	HMODULE DXconsistent = GetModuleHandle(L"DX_missing_models");
	HMODULE DXrefined = GetModuleHandle(L"SADXR");

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
			Init_DXmodern();
			___AMY_OBJECTS[4]->basicdxmodel->mats[2].attr_texId = 8;
			___AMY_OBJECTS[31]->basicdxmodel->mats[2].attr_texId = 8;
			___AMY_OBJECTS[33]->basicdxmodel->mats[2].attr_texId = 8;
			___AMY_MODELS[1]->mats[2].attr_texId = 8;
			___AMY_MODELS[2]->mats[2].attr_texId = 8;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->model = &attach_000119A0m;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->sibling->model = &attach_00011690m;
		}
	}

	else
	{
		if (DCcharacters)
		{
			Init_DCclassic();
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->model = &attach_004B86EC;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->sibling->model = &attach_004B84BC;
		}

		else
		{
			Init_DXclassic();
			___AMY_OBJECTS[4]->basicdxmodel->mats[2].attr_texId = 8;
			___AMY_OBJECTS[31]->basicdxmodel->mats[2].attr_texId = 8;
			___AMY_OBJECTS[33]->basicdxmodel->mats[2].attr_texId = 8;
			___AMY_MODELS[1]->mats[2].attr_texId = 8;
			___AMY_MODELS[2]->mats[2].attr_texId = 8;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->model = &attach_000119A0;
			AMY_OBJECTS[0]->child->child->sibling->sibling->sibling->sibling->child->child->sibling->sibling->sibling->child->sibling->child->sibling->model = &attach_00011690;
			if (DXconsistent)
			{
				*(NJS_MODEL_SADX*)0x0319F6E8 = attachdxc_02D9F6E8;
				WriteData((NJS_MOTION**)0x031C1C7C, &headdxc_motion);
			}
			else if (DXrefined)
			{
				*(NJS_MODEL_SADX*)0x0319F6E8 = attachdxc_02D9F6E8;
				WriteData((NJS_MOTION**)0x031C1C7C, &headdxc_motion);
			}
			else
			{
				*(NJS_MODEL_SADX*)0x0319F6E8 = attachdcc_02D9F6E8;
				WriteData((NJS_MOTION**)0x031C1C7C, &headdcc_motion);
			}
		}
	}

}

extern "C" __declspec(dllexport) const ModInfo SADXModInfo = { ModLoaderVer };