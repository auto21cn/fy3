//Mr.music yangzhou ����ͷ

inherit ROOM;

void enter_boad();

void create()
{
        set("short", "����ͷ");
        set("long", @LONG
	�������˺��ϵ�һ��æµ��С����ͷ�������������ۣ��������Ļʵ�
�������ݣ����ǳ˴��ڼ��ڴˣ���ͷ�ߵ�ʯ����ע������ͷ��������Ѳ��ɿ���
�����ö�[33m��[37mֻ��ͣ���ڴˣ������ݳǵ���Ҫ����ڰ���

LONG
        );


      set("item_desc", ([
              "chuan" : "��Щ��Ҳ�����Գˡ�\n",
                "��":     "���ʴ��ϴ��.\n",
                       ]));

        set("exits", ([ 
                      "up" : __DIR__"xiaodongmenqiao",
                      "north" : __DIR__"changku",
                     ]));
        set("objects", ([
                        __DIR__"npc/chuanjia": 1,
                        __DIR__"npc/chuanlaoda": 1,
                        ]) );

        setup();
}
