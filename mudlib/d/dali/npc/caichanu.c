inherit KZZNPC;
#include <ansi.h>

string query_save_file() { return DATA_DIR + "npc/灵琦儿"; }
void create()
{
#include <kzznpc.h>

	set("area_name","大理茶花山");
	set("area_file","/d/dali/chahuashan5.c");
	set("ziyuan","山茶");
	set("jizhi",30);
	set("kaifa",30);

        setup();
carry_object("/obj/cloth")->wear();
carry_object("/obj/std/weapon/muzhang")->wield();
}

#include <die.h>
