<?php

namespace App\Http\Controllers;

use App\Hobby;

class HomeController extends Controller
{
    /**
     * Show the application dashboard.
     *
     * @return \Illuminate\Contracts\Support\Renderable
     */
    public function index()
    {
        $hobbies = Hobby::select()
            ->where('user_id', auth()->id())
            ->orderBy('updated_at', 'DESC')
            ->get();

        return view('home')->with([
            'hobbies' => $hobbies,
        ]);
    }
}
