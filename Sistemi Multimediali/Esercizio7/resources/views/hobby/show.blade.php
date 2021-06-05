@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Hobby')
@section('page_description', 'Qui viene mostrato un solo hobby')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header"><h1 class="m-0">{{$hobby -> name}}</h1></div>

                    <div class="card-body">
                        <div class="row">
                            <div class="col-md-9">
                                <div class="mt-1">
                                    <h2>Descrizione: </h2>
                                    <p>{{$hobby -> description}}</p>
                                </div>

                                @if($hobby->tags->count() > 0)
                                    <div class="my-4">
                                        <h2 class="mb-3">Tag associati (clicca per rimuoverli): </h2>
                                        @foreach($hobby->tags as $tag)
                                            <a style="text-decoration: none"
                                               href="/hobby/{{$hobby->id}}/tag/{{$tag->id}}/detach">
                                    <span style="background-color: {{'#' . $tag->color}}"
                                          class="p-2 text-white font-weight-bold rounded mx-1">{{$tag -> name}}
                                    </span>
                                            </a>
                                        @endforeach
                                    </div>
                                @endif

                                @if($availableTags->count() > 0)
                                    <div class="my-4">
                                        <h2 class="mb-3">Tag disponibili (clicca per aggiungerli): </h2>
                                        @foreach($availableTags as $tag)
                                            <a style="text-decoration: none"
                                               href="/hobby/{{$hobby->id}}/tag/{{$tag->id}}/attach">
                                    <span style="background-color: {{'#' . $tag->color}}"
                                          class="p-2 text-white font-weight-bold rounded mx-1">{{$tag -> name}}
                                    </span>
                                            </a>
                                        @endforeach
                                    </div>
                                @endif
                            </div>
                            @if(file_exists('img/hobbies/' . $hobby->id . '_large.jpg') ||
                                file_exists('img/hobbies/' . $hobby->id . '_pixelated.jpg'))
                                <div class="col-md-3">
                                    @if(auth()->user() && file_exists('img/hobbies/' . $hobby->id . '_large.jpg'))
                                        <a href="/img/hobbies/{{$hobby->id}}_large.jpg"
                                           data-lightbox="{{$hobby->id}}_large.jpg"
                                           data-title="{{ $hobby->name }}">
                                            <img class="img-fluid" src="/img/hobbies/{{$hobby->id}}_large.jpg"
                                                 alt="Foto dell'hobby {{$hobby->name}}">
                                        </a>
                                        <i class="fa fa-search-plus"></i> Clicca l'immagine per allargarla
                                    @endif

                                    @if(!auth()->user() && file_exists('img/hobbies/' . $hobby->id . '_pixelated.jpg'))
                                        <a href="/img/hobbies/{{$hobby->id}}_pixelated.jpg"
                                           data-lightbox="{{$hobby->id}}_pixelated.jpg"
                                           data-title="{{ $hobby->name }}">
                                            <img class="img-fluid" src="/img/hobbies/{{$hobby->id}}_pixelated.jpg"
                                                 alt="Foto dell'hobby {{$hobby->name}}">
                                        </a>
                                        <i class="fa fa-search-plus"></i> Clicca l'immagine per allargarla
                                    @endif
                                </div>
                            @endif

                        </div>
                    </div>

                </div>
                <div class="mt-3">
                    <a class="btn btn-link btn-sm" href="{{\Illuminate\Support\Facades\URL::previous()}}">
                        <i class="fas fa-arrow-circle-up"></i> Ritorna agli hobby
                    </a>
                </div>
            </div>
        </div>
@endsection
