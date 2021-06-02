@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Hobby')
@section('page_description', 'Tutti gli hobby sono visualizzati qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">Hobby</div>

                    <div class="card-body">
                        <ul class="list-group">
                            @foreach($hobbies as $hobby)
                                <li class="list-group-item"><a class="btn-link"
                                                               href="hobby/{{$hobby->id}}">{{$hobby -> name}}</a>
                                    <a class="btn btn-sm btn-light ml-4" href="hobby/{{$hobby->id}}/edit"><i
                                            class="fas fa-edit"></i> Modifica</a>
                                    <form class="float-right" style="display: inline" action="hobby/{{$hobby->id}}"
                                          method="post">
                                        @csrf
                                        @method('DELETE')
                                        <input class="btn btn-sm btn-outline-danger" type="submit" value="Elimina"/>
                                    </form>
                                </li>
                            @endforeach
                        </ul>
                    </div>
                </div>
                <div class="mt-3">
                    <a class="btn btn-success btn-sm" href="hobby/create">
                        <i class="fas fa-plus-circle"></i> Crea un nuovo Hobby
                    </a>
                </div>
            </div>
        </div>
@endsection
