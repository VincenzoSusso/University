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
                            <div class="row">
                                @isset($hobbies)
                                    <div class="col-md-9">
                                        @if($hobbies->count() > 0)
                                            <h2>I miei hobby:</h2>
                                            <ul class="list-group">
                                                @foreach($hobbies as $hobby)
                                                    <li class="list-group-item">
                                                        <a title="Mostra l'hobby" style="text-decoration: none"
                                                           class="btn-link" href="/hobby/{{$hobby->id}}">
                                                            @if(file_exists('img/hobbies/' . $hobby->id . '_thumb.jpg'))
                                                                <img src="/img/hobbies/{{$hobby->id}}_thumb.jpg"
                                                                     alt="thumb">
                                                            @endif
                                                            <span class="ml-2">{{$hobby -> name}}</span>
                                                        </a>

                                                        <a class="btn btn-sm btn-light border-dark ml-2"
                                                           href="/hobby/{{$hobby->id}}/edit">
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
                                            <h2>Non hai inserito nessun hobby</h2>
                                        @endif
                                    </div>
                                    @if(file_exists('img/users/' . Auth::id() . '_large.jpg'))
                                        <div class="col-md-3">
                                            <img class="img-thumbnail" src="/img/users/{{Auth::id()}}_large.jpg"
                                                 alt="{{ auth()->user()->name }}">
                                        </div>
                                    @endif
                                @else
                                    <h2>Non hai ancora creato degli hobby, crea il tuo primo hobby usando il pulsante
                                        disponibile qui sotto</h2>
                                @endisset
                            </div>
                        @endauth

                        @guest
                            <p class="text-center">Benvenuto, iscriviti o accedi per usufruire di questo fantastico
                                social network!</p>
                        @endguest

                        @auth
                            <div class="mt-5 float-left">
                                <a class="btn btn-success btn-sm" href="/hobby/create">
                                    <i class="fas fa-plus-circle"></i> Crea un nuovo Hobby
                                </a>
                            </div>
                            <div class="mt-5 ml-3 float-left">
                                <a class="btn btn-sm btn-light border-dark ml-2"
                                   href="/user/{{Auth::id()}}/edit"><i
                                        class="fas fa-edit"></i> Modifica il profilo
                                </a>
                            </div>
                        @endauth

                    </div>
                </div>
            </div>
        </div>
@endsection
