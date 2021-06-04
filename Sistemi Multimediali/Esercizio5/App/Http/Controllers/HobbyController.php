<?php

namespace App\Http\Controllers;

use App\Hobby;
use App\Tag;
use Illuminate\Http\Request;

class HobbyController extends Controller
{
    public function __construct()
    {
        $this->middleware('auth')->except(['index', 'show']);
    }

    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $hobbies = Hobby::orderBy('created_at', 'DESC')->paginate(10);

        return view('hobby.index')->with([
            'hobbies' => $hobbies
        ]);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        return view('hobby.create');
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
            'name' => 'required|min:3',
            'description' => 'required|min:5',
        ]);

        $hobby = new Hobby([
            'user_id' => auth()->id(),
            'name' => $request['name'],
            'description' => $request['description'],
        ]);

        $hobby->save();

        return redirect('hobby/' . $hobby->id)->with([
            'message_success' => 'L\'hobby "' . $hobby->name . '" è stato creato',
            'message_warning' => 'Aggiungi dei tag all\'hobby "' . $hobby->name . '"',
        ]);
    }

    /**
     * Display the specified resource.
     *
     * @param \App\Hobby $hobby
     * @return \Illuminate\Http\Response
     */
    public function show(hobby $hobby)
    {
        $availableTags = Tag::all()->diff(Hobby::findOrFail($hobby->id)->tags);

        return view('hobby.show')->with([
            'hobby' => $hobby,
            'availableTags' => $availableTags,
        ]);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param \App\Hobby $hobby
     * @return \Illuminate\Http\Response
     */
    public function edit(hobby $hobby)
    {
        return view('hobby/edit')->with([
            'hobby' => $hobby,
        ]);
    }

    /**
     * Update the specified resource in storage.
     *
     * @param \Illuminate\Http\Request $request
     * @param \App\Hobby $hobby
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, Hobby $hobby)
    {
        $request->validate([
            'name' => 'required|min:3',
            'description' => 'required|min:5',
        ]);

        $hobby->update([
            'name' => $request['name'],
            'description' => $request['description'],
        ]);

        return redirect('hobby')->with([
            'message_success' => 'L\'hobby "' . $hobby->name . '" è stato modificato',
        ]);
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param \App\Hobby $hobby
     * @return \Illuminate\Http\Response
     */
    public function destroy(hobby $hobby)
    {
        $old_name = $hobby->name;

        try {
            $hobby->delete();
        } catch (\Exception $e) {
            return redirect('hobby')->with([
                'message_warning' => 'C\'è stato un errore con l\'hobby "' . $old_name . '"',
            ]);
        }

        return redirect('hobby')->with([
            'message_success' => 'L\'hobby "' . $old_name . '" è stato eliminato']);
    }

}
