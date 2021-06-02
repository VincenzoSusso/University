<?php

namespace App\Http\Controllers;

use App\Hobby;
use Illuminate\Http\Request;

class HobbyController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $hobbies = Hobby::all();

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
            'name' => $request['name'],
            'description' => $request['description'],
        ]);

        $hobby->save();

        return redirect('hobby/')->with([
            'message_success' => 'L\'hobby "' . $hobby->name . '" è stato creato']);

        /*return $this->index()->with([
            'message_success' => 'L\'hobby "' . $hobby->name . '" è stato creato',
        ]);*/
    }

    /**
     * Display the specified resource.
     *
     * @param \App\Hobby $hobby
     * @return \Illuminate\Http\Response
     */
    public function show(hobby $hobby)
    {
        return view('hobby.show')->with([
            'hobby' => $hobby,
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
