@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Home')
@section('page_description', 'Pagina principale del social network \"I Miei Hobby\"')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">
                        @auth
                            <h1 class="h1 m-0">{{\Illuminate\Support\Facades\Auth::user()->name}}</h1>
                        @endauth

                        @guest
                            <h1 class="h1 m-0">Home</h1>
                        @endguest
                    </div>

                    <div class="card-body">
                        @auth
                            @isset($hobbies)
                                <h2>I miei hobby:</h2>
                                <ul class="list-group">
                                    @foreach($hobbies as $hobby)
                                        <li class="list-group-item">
                                            <a class="btn-link" href="/hobby/{{$hobby->id}}">
                                                {{$hobby -> name}}
                                            </a>

                                            <a class="btn btn-sm btn-light ml-2" href="/hobby/{{$hobby->id}}/edit">
                                                <i class="fas fa-edit"></i> Modifica
                                            </a>

                                            <form class="ml-2" style="display: inline"
                                                  action="hobby/{{$hobby->id}}"
                                                  method="post">
                                                @csrf
                                                @method('DELETE')
                                                <input class="btn btn-sm btn-outline-danger" type="submit"
                                                       value="Elimina"/>
                                            </form>
                                            <span class="mr-2 text-center float-right">
                                                Creato {{$hobby->created_at->diffForHumans()}}
                                            </span>
                                            <div class="my-3">
                                                @foreach($hobby->tags as $tag)
                                                    <a style="text-decoration: none" class="float-left ml-1"
                                                       href="/hobby/tag/{{$tag->id}}">
                                                <span style="background-color: {{'#' . $tag->color}}"
                                                      class="p-2 text-white font-weight-bold rounded">{{$tag -> name}}
                                                </span>
                                                    </a>
                                                @endforeach
                                            </div>
                                        </li>
                                    @endforeach
                                </ul>
                            @else
                                <h2>Non hai ancora creato degli hobby, crea il tuo primo hobby usando il pulsante
                                    disponibile qui sotto</h2>
                            @endisset
                        @endauth

                        @guest
                            <p class="text-center">Benvenuto, iscriviti o accedi per usufruire di questo fantastico
                                social network!</p>
                        @endguest

                        @auth
                            <div class="mt-5">
                                <a class="btn btn-success btn-sm" href="/hobby/create">
                                    <i class="fas fa-plus-circle"></i> Crea un nuovo Hobby
                                </a>
                            </div>
                        @endauth

                    </div>
                </div>
            </div>
        </div>
@endsection
