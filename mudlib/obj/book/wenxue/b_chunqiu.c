// 

inherit ITEM;

void create()
{
	set_name("《春秋》",({"chunqiu","shu","book","chun qiu"}));
        set_weight(100);
        set("unit", "本");
        set("long",
		"一本可以提高文化的好书。\n"
             );
	set("value",3000);
        set("skill", ([
		"name":"literate",
		"max_skill":60,
        ]) );
}
 
