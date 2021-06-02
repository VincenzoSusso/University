<?php

use Illuminate\Database\Seeder;
use App\Tag;

class TagSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        $tags = [
            'Sport' => 'f08080',
            'Relax' => 'ffc0cb',
            'Divertimento' => '9400d3',
            'Natura' => '00ff00',
            'Ispirazione' => 'ffff00',
            'Amici' => '00008b',
            'Amore' => 'ff0000',
            'Interesse' => '4169e1',
        ];

        foreach ($tags as $key => $value) {
            $tag = new Tag(
                [
                    'name' => $key,
                    'color' => $value
                ]
            );

            $tag->save();
        }
    }
}
