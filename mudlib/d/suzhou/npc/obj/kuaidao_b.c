// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name("快刀刀法图",({"tu","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
	set("long","一本小册子，画着些使用快刀刀法的图解。\n");
		set("material", "paper");
		set("value",2500);
		set("skill", ([
	"name" :"kuaidao-daofa",
	"exp_required":10000,
	"max_skill":30,
	"sen_cost":10+random(10),
		]) );
	}
}
