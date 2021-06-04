<?php

namespace App\Http\Controllers;

use App\Tag;
use App\Hobby;

class HobbyTagController extends Controller
{
    public function getFilteredHobbies($tag_id)
    {
        $hobbies = Tag::findOrFail($tag_id)->filteredHobbies()->paginate(10);
        $filter = Tag::findOrFail($tag_id);

        return view('hobby.index')->with([
            'hobbies' => $hobbies,
            'filter' => $filter,
        ]);
    }

    public function attachTag($hobby_id, $tag_id)
    {
        $hobby = Hobby::findOrFail($hobby_id);
        $tag = Tag::findOrFail($tag_id);

        $hobby->tags()->attach($tag_id);

        return redirect('hobby/' . $hobby_id)->with([
            'message_success' => 'Il tag "' . $tag->name . '" è stato aggiunto all\'hobby "' . $hobby->name . '"',
        ]);

    }

    public function detachTag($hobby_id, $tag_id)
    {
        $hobby = Hobby::findOrFail($hobby_id);
        $tag = Tag::findOrFail($tag_id);

        $hobby->tags()->detach($tag_id);

        return redirect('hobby/' . $hobby_id)->with([
            'message_success' => 'Il tag "' . $tag->name . '" è stato rimosso dall\'hobby "' . $hobby->name . '"',
        ]);
    }
}
