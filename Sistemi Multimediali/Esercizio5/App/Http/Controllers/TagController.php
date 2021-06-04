<?php

namespace App\Http\Controllers;

use App\Tag;
use Illuminate\Http\Request;

class TagController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $tags = Tag::all();

        return view('tag.index')->with([
            'tags' => $tags
        ]);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        return view('tag.create');
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param \Illuminate\Http\Request $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $request->validate([
            'name' => 'required',
            'color' => ['required', 'regex:/^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$/']
        ]);

        $tag = new Tag([
            'name' => $request['name'],
            'color' => ltrim($request['color'], '#'),
        ]);

        $tag->save();

        return redirect('tag/')->with([
            'message_success' => 'Il tag "' . $tag->name . '" è stato creato',
        ]);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param \App\Tag $tag
     * @return \Illuminate\Http\Response
     */
    public function edit(Tag $tag)
    {
        return view('tag/edit')->with([
            'tag' => $tag,
        ]);
    }

    /**
     * Update the specified resource in storage.
     *
     * @param \Illuminate\Http\Request $request
     * @param \App\Tag $tag
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, Tag $tag)
    {
        $request->validate([
            'name' => 'required',
            'color' => ['required', 'regex:/^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$/']
        ]);

        $tag->update([
            'name' => $request['name'],
            'color' => ltrim($request['color'], '#'),
        ]);

        return redirect('tag')->with([
            'message_success' => 'Il tag "' . $tag->name . '" è stato modificato',
        ]);
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param \App\Tag $tag
     * @return \Illuminate\Http\Response
     */
    public function destroy(Tag $tag)
    {
        $old_name = $tag->name;

        try {
            $tag->delete();
        } catch (\Exception $e) {
            return redirect('tag')->with([
                'message_warning' => 'C\'è stato un errore con il tag "' . $old_name . '"',
            ]);
        }

        return redirect('tag')->with([
            'message_success' => 'Il tag "' . $old_name . '" è stato eliminato',
        ]);
    }
}
